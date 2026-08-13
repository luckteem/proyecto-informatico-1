#include <Adafruit_NeoPixel.h>

#define BUZZ       6
#define NEOPIX    13
#define BTN_START  8
#define TOTAL_LEDS 48   // 8 tiras x 6 LEDs = 48 LEDs

Adafruit_NeoPixel pixel = Adafruit_NeoPixel(TOTAL_LEDS, NEOPIX, NEO_GRB + NEO_KHZ800);

bool ultimoEstadoBoton = HIGH;

void setup() {
  pinMode(BUZZ, OUTPUT);
  pinMode(BTN_START, INPUT_PULLUP);
  Serial.begin(9600);

  pixel.begin();
  pixel.clear();
  pixel.show();

  randomSeed(analogRead(A4));
}

void loop() {
  bool estadoActualBoton = digitalRead(BTN_START);

  if (estadoActualBoton == LOW && ultimoEstadoBoton == HIGH) {
    delay(50);
    if (digitalRead(BTN_START) == LOW) {

      for (int i = 0; i < 10; i++) {
        int d1 = random(1, 7);
        int d2 = random(1, 7);

        pixel.clear();

        
        int patrones[7][7] = {
          {0,0,0,0,0,0,0}, // índice 0 no se usa
          {0,0,1,0,0,0,0}, // dado 1 → centro
          {1,0,0,0,1,0,0}, // dado 2 → dos esquinas
          {1,0,1,0,1,0,0}, // dado 3 → esquinas + centro
          {1,1,0,0,1,1,0}, // dado 4 → cuatro esquinas
          {1,1,1,0,1,1,0}, // dado 5 → cuatro esquinas + centro
          {1,1,0,1,1,0,1}  // dado 6 → dos columnas completas
        };

        for (int p = 0; p < 7; p++) {
          if (patrones[d1][p] == 1) {
            for (int l = 0; l < 6; l++) {
              pixel.setPixelColor(p*3 + l, pixel.Color(255,0,0));
            }
          }
        }

        for (int p = 0; p < 7; p++) {
          if (patrones[d2][p] == 1) {
            for (int l = 0; l < 6; l++) {
              pixel.setPixelColor(24 + p*3 + l, pixel.Color(255,0,0));
            }
          }
        }

        pixel.show();
        delay(100);
      }

      int resultadoD1 = random(1, 7);
      int resultadoD2 = random(1, 7);
      int suma = resultadoD1 + resultadoD2;

      pixel.clear();

      int patrones[7][7] = {
        {0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0},
        {1,0,0,0,1,0,0},
        {1,0,1,0,1,0,0},
        {1,1,0,0,1,1,0},
        {1,1,1,0,1,1,0},
        {1,1,0,1,1,0,1}
      };

      for (int p = 0; p < 7; p++) {
        if (patrones[resultadoD1][p] == 1) {
          for (int l = 0; l < 6; l++) {
            pixel.setPixelColor(p*3 + l, pixel.Color(255,0,0));
          }
        }
      }

      for (int p = 0; p < 7; p++) {
        if (patrones[resultadoD2][p] == 1) {
          for (int l = 0; l < 6; l++) {
            pixel.setPixelColor(24 + p*3 + l, pixel.Color(255,0,0));
          }
        }
      }

      pixel.show();

      Serial.print("Dado 1: ");
      Serial.print(resultadoD1);
      Serial.print(" | Dado 2: ");
      Serial.print(resultadoD2);
      Serial.print(" | Suma: ");
      Serial.println(suma);

      if (suma == 7) {
        for (int i = 0; i < 5; i++) {
          pixel.clear();
          pixel.show();
          tone(BUZZ, 1000);
          delay(200);

          for (int p = 0; p < 7; p++) {
            if (patrones[resultadoD1][p] == 1) {
              for (int l = 0; l < 6; l++) {
                pixel.setPixelColor(p*3 + l, pixel.Color(255,0,0));
              }
            }
          }
          for (int p = 0; p < 7; p++) {
            if (patrones[resultadoD2][p] == 1) {
              for (int l = 0; l < 6; l++) {
                pixel.setPixelColor(24 + p*3 + l, pixel.Color(255,0,0));
              }
            }
          }
          pixel.show();
          tone(BUZZ, 800);
          delay(200);
        }
        noTone(BUZZ);
      }
    }
  }

  ultimoEstadoBoton = estadoActualBoton;
}
