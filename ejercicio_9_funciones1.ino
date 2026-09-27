void llenarVectorMultiplo10(int v[], int tam) {
  for (int i = 0; i < tam; i++) {
    v[i] = random(0, 11) * 10;
  }
}

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  int numeros[5];
  llenarVectorMultiplo10(numeros, 5);
  for (int i = 0; i < 5; i++) {
    Serial.println(numeros[i]);
  }
}

void loop() {
}
