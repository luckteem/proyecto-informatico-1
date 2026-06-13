#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 12
#define POT A0
#define BUTTON 2

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int efecto = 0;     // controla qué efecto se ejecuta
int velocidad = 500; // tiempo entre cambios

void setup() {
  pixels.begin(); // inicializa tira de LEDs
  pinMode(BUTTON, INPUT_PULLUP); // botón con resistencia interna
}

void loop() {
  int potValue = analogRead(POT); // lectura potenciómetro
  velocidad = (potValue / 10) + 100; // ajusta velocidad

  // cambio de efecto con botón
  if (digitalRead(BUTTON) == LOW) {
    efecto = efecto + 1;
    if (efecto > 2) {
      efecto = 0; // vuelve al primero
    }
    delay(300); // evita rebote
  }

  // efecto 1: enciende uno por uno con colores distintos
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
    // ... sigue con otros colores hasta el pixel 11
  }

  // efecto 2: barrido adelante y atrás
  if (efecto == 1) {
    pixels.clear();
    pixels.setPixelColor(0, pixels.Color(0, 255, 0)); // verde al inicio
    pixels.show();
    delay(velocidad);
    // avanza encendiendo cada LED en verde
    // luego retrocede encendiendo cada LED en azul
  }

  // efecto 3: pares e impares
  if (efecto == 2) {
    pixels.clear();
    // enciende LEDs pares en rojo
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
    // enciende LEDs impares en azul
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
