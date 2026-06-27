int sensorTemp = A0;     // LM35 en A0
int sensorPIR = 2;       // PIR en D2
int pinMotor = 9;        // Motor controlado por PWM en D9
int pinLampara = 8;      // Lámpara controlada en D8

void setup() {
  pinMode(sensorPIR, INPUT);
  pinMode(pinMotor, OUTPUT);
  pinMode(pinLampara, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lecturaTemp = analogRead(sensorTemp);
  float temperatura = (lecturaTemp * 5.0 * 100.0) / 1024.0; // LM35: 10mV/°C
  int movimiento = digitalRead(sensorPIR);

  Serial.print("Temp: ");
  Serial.print(temperatura);
  Serial.print(" °C | Movimiento: ");
  Serial.println(movimiento);

  // --- Lógica del ventilador ---
  if (temperatura >= 50) {
    analogWrite(pinMotor, 255); // Máxima velocidad
    digitalWrite(pinLampara, movimiento == HIGH ? HIGH : LOW); // Lámpara depende del PIR
  } else {
    if (movimiento == HIGH) {
      // Persona presente: velocidad proporcional
      int velocidadPWM = 0;
      if (temperatura <= 15) velocidadPWM = 50;
      else if (temperatura == 30) velocidadPWM = 150;
      else if (temperatura > 30 && temperatura < 50) {
        // Escalado lineal entre 150 y 255
        velocidadPWM = map(temperatura, 30, 50, 150, 255);
      }
      analogWrite(pinMotor, velocidadPWM);
      digitalWrite(pinLampara, HIGH);
    } else {
      // Sin persona
      analogWrite(pinMotor, 0);
      digitalWrite(pinLampara, LOW);
    }
  }
}
