#include <LiquidCrystal.h>

//LiquidCrystal (rs, e, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 10, 2, 1, 13);

// Variables de pines
int ledR = 3;
int ledG = 4;
int ledB = 5;
int buzzer = 6;

int temp = A0;    // LM35
int ldr = A1;     // Fotoresistor o sensor de luz o ldr
int pir = 7;      // Sensor movimiento

int trig = 8;     // Ultrasonico
int echo = 9;

// Variables de lectura
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
  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.println("Sistema de alarma iniciado");
  delay(1000);
}

void loop()
{
  // Leer temperatura LM35
  tempValor = analogRead(temp);
  tempC = tempValor * 0.488; // Conversion a °C
  
  // Leer luz LDR
  luzValor = analogRead(ldr);
  
  // Leer movimiento PIR
  movimiento = digitalRead(pir);
  
  // Leer distancia ultrasonico
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delay(5);
  digitalWrite(trig, LOW);
  tiempoEcho = pulseIn(echo, HIGH);
  distancia = tiempoEcho / 58;
  
  
  //Mostrar en LCD
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
  
  // Mostrar en monitor serial
  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.print("C  Luz: ");
  Serial.print(luzValor/10);
  Serial.print("%  Dist: ");
  Serial.print(distancia);
  Serial.print("cm  Mov: ");
  Serial.println(movimiento);
  
  // Condicion de noche: luz menor a 20% = valor < 200
  if(luzValor < 200)
  {
    // Alerta temperatura > 39°C
    if(tempC > 39)
    {
      digitalWrite(ledR, HIGH);
      digitalWrite(ledG, LOW);
      digitalWrite(ledB, LOW);
      digitalWrite(buzzer, HIGH);
      delay(200);
      digitalWrite(buzzer, LOW);
      Serial.println("ALERTA: Toque detectado");
    }
    // Alerta movimiento
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
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, LOW);
      digitalWrite(ledB, LOW);
      digitalWrite(buzzer, LOW);
    }
  }
  // Condicion de dia
  else
  {
    // Alerta distancia < 100cm
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
    // Alerta movimiento dia
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
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, LOW);
      digitalWrite(ledB, LOW);
      digitalWrite(buzzer, LOW);
    }
  }
  
  delay(500);
}