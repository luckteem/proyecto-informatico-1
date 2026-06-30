#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#include <Adafruit_NeoPixel.h>

#define ldr A1
#define PIN 9
#define NUMPIXELS 6
#define boton 7

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int efecto = 0;     // controla qué efecto se ejecuta
int velocidad = 500; // tiempo entre cambios
int luzValor = 0;
void setup() {
  pixels.begin();
  pinMode(boton, INPUT);
  pinMode(ldr, INPUT);
  lcd.begin(16, 2); 
  Serial.begin(9600);
  Serial.print("Sistema de alarma iniciado");
  delay(1000);
}

void loop() {
 

  // cambio de efecto con botón
  if (digitalRead(boton) == LOW) {
    efecto = efecto + 1;
    if (efecto > 2) {
      efecto = 0; // vuelve al primero
    }
    delay(300); // evita rebote
  }

  // efecto 1: enciende uno por uno con colores distintos
  if (luzValor > 0 && luzValor<30 ) {
    pixels.clear();
    pixels.setPixelColor(0, pixels.Color(0, 255, 0)); // verde
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(1, pixels.Color(0, 255,0)); // verde
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(2, pixels.Color(0, 255, 0)); // verde
    pixels.show();
    delay(velocidad);
      pixels.clear();
    pixels.setPixelColor(3, pixels.Color(0, 255, 0)); // verde
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(4, pixels.Color(0, 255, 0)); // verde
    pixels.show();
    delay(velocidad);
    pixels.clear();
    pixels.setPixelColor(5, pixels.Color(0, 255, 0)); //verde
    pixels.show();
    delay(velocidad);
    // ... sigue con otros colores hasta el pixel 11
  }

  // efecto 2: barrido adelante y atrás
  if (luzValor > 30 && luzValor<70 ) {
    pixels.clear();
    pixels.setPixelColor(1, pixels.Color(255, 255, 0));
    pixels.show();
    delay(velocidad);
    pixels.setPixelColor(2, pixels.Color(255, 255, 0));
    pixels.show();
    delay(velocidad);
    pixels.show();
    delay(velocidad);
  }

  // efecto 3: pares e impares
  if (efecto == 2) {
    pixels.clear();
   
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.setPixelColor(1, pixels.Color(255, 0, 0));
    pixels.setPixelColor(2, pixels.Color(255, 0, 0));
    pixels.setPixelColor(3, pixels.Color(255, 0, 0));
    pixels.setPixelColor(4, pixels.Color(255, 0, 0));
    pixels.setPixelColor(5, pixels.Color(255, 0, 0));
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