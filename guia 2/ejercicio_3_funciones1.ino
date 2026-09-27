#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void mostrarBienvenida() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Bienvenido!");
}

void mostrarInicioJuego() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Inicio del juego");
}

void mostrarFinJuego() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Fin del juego");
}

void mostrarPuntuacion() {
  int puntaje = random(0,100);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Puntuacion:");
  lcd.setCursor(0,1);
  lcd.print(puntaje);
}

void setup() {
  lcd.begin(16,2);
  randomSeed(analogRead(0));
  mostrarBienvenida();
  delay(2000);
  mostrarInicioJuego();
  delay(2000);
  mostrarPuntuacion();
  delay(2000);
  mostrarFinJuego();
}

void loop() {
}
