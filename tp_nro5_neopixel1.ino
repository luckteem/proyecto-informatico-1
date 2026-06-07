#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 12
#define POT A0
#define BUTTON 2

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int efecto = 0;
int velocidad = 500;

void setup() {
  pixels.begin();
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  int potValue = analogRead(POT);
  velocidad = (potValue / 10) + 100; // ajusta velocidad sin map()

  if (digitalRead(BUTTON) == LOW) {
    efecto = efecto + 1;
    if (efecto > 2) {
      efecto = 0;
    }
    delay(300); // anti rebote
  }

  // Efecto 1: encender uno por uno con colores distintos
  if (efecto == 0) {
    pixels.clear();
    pixels.setPixelColor(0, pixels.Color(255, 0, 0)); // rojo
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(1, pixels.Color(0, 255, 0)); // verde
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(2, pixels.Color(0, 0, 255)); // azul
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(3, pixels.Color(255, 255, 0)); // amarillo
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(4, pixels.Color(255, 0, 255)); // magenta
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(5, pixels.Color(0, 255, 255)); // cyan
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(6, pixels.Color(255, 128, 0)); // naranja
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(7, pixels.Color(128, 0, 255)); // violeta
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(8, pixels.Color(255, 255, 255)); // blanco
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(9, pixels.Color(128, 128, 128)); // gris
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(10, pixels.Color(0, 128, 128)); // turquesa
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(11, pixels.Color(128, 255, 0)); // lima
    pixels.show();
    delay(velocidad);
  }

  // Efecto 2: barrido adelante y atrás
  if (efecto == 1) {
    pixels.clear();
    pixels.setPixelColor(0, pixels.Color(0, 255, 0));
    pixels.show();
    delay(velocidad);
    pixels.setPixelColor(1, pixels.Color(0, 255, 0));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(2, pixels.Color(0, 255, 0));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(3, pixels.Color(0, 255, 0));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(4, pixels.Color(0, 255, 0));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(5, pixels.Color(0, 255, 0));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(6, pixels.Color(0, 255, 0));
    pixels.show();
    delay(velocidad);
    pixels.setPixelColor(7, pixels.Color(0, 255, 0));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(8, pixels.Color(0, 255, 0));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(9, pixels.Color(0, 255, 0));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(10, pixels.Color(0, 255, 0));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(11, pixels.Color(0, 255, 0));
    pixels.show();
    delay(velocidad);

    // Barrido atrás
    pixels.clear();
    pixels.setPixelColor(11, pixels.Color(0, 0, 255));
    pixels.show();
     delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(10, pixels.Color(0, 0, 255));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(9, pixels.Color(0, 0, 255));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(8, pixels.Color(0, 0, 255));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(7, pixels.Color(0, 0, 255));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(6, pixels.Color(0, 0, 255));
    pixels.show();
    delay(velocidad);
      pixels.clear();
    pixels.setPixelColor(5, pixels.Color(0, 0, 255));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(4, pixels.Color(0, 0, 255));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(3, pixels.Color(0, 0, 255));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(2, pixels.Color(0, 0, 255));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(1, pixels.Color(0, 0, 255));
    pixels.show();
    delay(velocidad);
     pixels.clear();
    pixels.setPixelColor(0, pixels.Color(0, 0, 255));
    pixels.show();
    delay(velocidad);
  }

  // Efecto 3: pares e impares
  if (efecto == 2) {
    pixels.clear();
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.setPixelColor(2, pixels.Color(255, 0, 0));
    pixels.setPixelColor(4, pixels.Color(255, 0, 0));
    pixels.setPixelColor(6, pixels.Color(255, 0, 0));
    pixels.setPixelColor(8, pixels.Color(255, 0, 0));
    pixels.setPixelColor(10, pixels.Color(255, 0, 0));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.show();
    delay(velocidad);
    pixels.setPixelColor(1, pixels.Color(0, 0, 255));
    pixels.setPixelColor(3, pixels.Color(0, 0, 255));
    pixels.setPixelColor(5, pixels.Color(0, 0, 255));
    pixels.setPixelColor(7, pixels.Color(0, 0, 255));
    pixels.setPixelColor(9, pixels.Color(0, 0, 255));
    pixels.setPixelColor(11, pixels.Color(0, 0, 255));
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.show();
    delay(velocidad);
   }
}
