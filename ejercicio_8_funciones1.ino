bool esMultiplo(int numero, int divisor) {
  if (divisor == 0) return false;
  return numero % divisor == 0;
}

void setup() {
  Serial.begin(9600);
  int a = 20;
  int b = 5;
  if (esMultiplo(a, b)) {
    Serial.println("Es multiplo");
  } else {
    Serial.println("No es multiplo");
  }
}

void loop() {
}
