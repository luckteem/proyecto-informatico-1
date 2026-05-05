int potPin = A0;
int buzzer = 9;
int valor;
int frecuencia;

void setup() {
  pinMode( 9 , OUTPUT );
}

void loop() {
  valor = analogRead(A0);

  frecuencia = map(valor, 0, 1023, 100, 2000);

  tone( 9 , frecuencia );

  delay(50);
}