#include <LiquidCrystal.h>

//LiquidCrystal (rs, e, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 10, 2, 1, 13);

// pines para LED RGB y buzzer
int ledR = 3;
int ledG = 4;
int ledB = 5;
int buzzer = 6;

// sensores conectados
int temp = A0;    // LM35 mide temperatura
int ldr = A1;     // sensor de luz
int pir = 7;      // sensor de movimiento
int trig = 8;     // ultrasonico trigger
int echo = 9;     // ultrasonico echo

// variables de lectura
int tempValor = 0;
int tempC = 0;
int luzValor = 0;
int movimiento = 0;
int distancia = 0;
int tiempoEcho = 0;

void setup()
{
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  pinMode(pir, INPUT);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  lcd.begin(16, 2); // inicializa pantalla LCD
  Serial.begin(9600);
  Serial.println("Sistema de alarma iniciado");
  delay(1000);
}

void loop()
{
  // lectura de temperatura LM35
  tempValor = analogRead(temp);
  tempC = tempValor * 0.488; // convierte a grados Celsius
  
  // lectura de luz ambiente
  luzValor = analogRead(ldr);
  
  // lectura de movimiento PIR
  movimiento = digitalRead(pir);
  
  // lectura de distancia ultrasonico
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delay(5);
  digitalWrite(trig, LOW);
  tiempoEcho = pulseIn(echo, HIGH);
  distancia = tiempoEcho / 58; // calcula en cm
  
  // muestra en LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T: ");
  lcd.print(tempValor, 0);
  lcd.print("L: ");
  lcd.print(luzValor, 0);
  lcd.print("% ");
  lcd.setCursor(0, 1);
  lcd.print("D:");
  lcd.print(distancia, 0);
  lcd.print("cm M: ");
  lcd.print(movimiento);
  
  // muestra en monitor serie
  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.print("C  Luz: ");
  Serial.print(luzValor/10);
  Serial.print("%  Dist: ");
  Serial.print(distancia);
  Serial.print("cm  Mov: ");
  Serial.println(movimiento);
  
  // condición de noche: luz baja
  if(luzValor < 200)
  {
    // alerta si temperatura alta
    if(tempC > 39)
    {
      digitalWrite(ledR, HIGH); // rojo encendido
      digitalWrite(ledG, LOW);
      digitalWrite(ledB, LOW);
      digitalWrite(buzzer, HIGH); // buzzer breve
      delay(200);
      digitalWrite(buzzer, LOW);
      Serial.println("ALERTA: Toque detectado");
    }
    // alerta si hay movimiento
    else if(movimiento == 1)
    {
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, HIGH); // verde encendido
      digitalWrite(ledB, LOW);
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      Serial.println("ADVERTENCIA: Movimiento cerca");
    }
    else
    {
      // todo apagado si no hay alerta
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, LOW);
      digitalWrite(ledB, LOW);
      digitalWrite(buzzer, LOW);
    }
  }
  // condición de día
  else
  {
    // alerta si distancia menor a 100 cm
    if(distancia < 100 && distancia > 0)
    {
      digitalWrite(ledR, HIGH);
      digitalWrite(ledG, LOW);
      digitalWrite(ledB, LOW);
      digitalWrite(buzzer, HIGH);
      delay(150);
      digitalWrite(buzzer, LOW);
      delay(150);
      digitalWrite(buzzer, HIGH);
      delay(150);
      digitalWrite(buzzer, LOW);
      Serial.println("ALERTA: Muy cerca de la obra");
    }
    // alerta si hay movimiento
    else if(movimiento == 1)
    {
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledB, LOW);
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      Serial.println("ADVERTENCIA: Movimiento cerca");
    }
    else
    {
      // todo apagado si no hay alerta
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, LOW);
      digitalWrite(ledB, LOW);
      digitalWrite(buzzer, LOW);
    }
  }
  
  delay(500); // pausa entre lecturas
}


/*
int trig = 2;
int echo= 3;
int buzzer = 4;
int ledR = 5;
int ledG = 6;
int ledB = 7;
int boton = 8;

bool alarmaActiva = false; // 1 = activada, 0 = desactivada
bool estadoBotonInicial = false;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(boton, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Botón: alterna estado de alarma
  int estadoBoton = digitalRead(boton);
  if (estadoBoton == HIGH && estadoBotonInicial== LOW) {
    alarmaActiva = !alarmaActiva;
    delay(300); // evita rebotes
  }
  estadoBotonInicial= estadoBoton;

  // Medición de distancia
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int duracion = pulseIn(echo, HIGH);
  int distancia = duracion * 0.034 / 2;

  Serial.print("Distancia actual del objeto: ");
  Serial.print(distancia);
  Serial.print(" cm | Alarma: ");
  if (alarmaActiva == true) Serial.println("Activada");
  else Serial.println("Desactivada");

  // Lógica de alarma
  if (alarmaActiva == false) {
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledB, HIGH); // azul
    digitalWrite(buzzer, LOW);
  } else {
    if (distancia > 150) { // Estado 1
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledB, LOW);
      digitalWrite(buzzer, LOW);
    } else if (distancia >= 50 && distancia <= 150) { // Estado 2
      digitalWrite(ledR, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledB, LOW);
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);
      delay(500);
    } else if (distancia < 50) { // Estado 3
      digitalWrite(ledR, HIGH);
      digitalWrite(ledG, LOW);
      digitalWrite(ledB, LOW);
      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);
      delay(50);
    }
  }
}
*/
