int sensorPIR = 7;
int led = 8;

void setup() {
  pinMode(sensorPIR, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int movimiento = digitalRead(sensorPIR);
  if (movimiento == HIGH) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
