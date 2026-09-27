int lanzarDado(int lados) {
  return random(1, lados + 1);
}

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  int resultado = lanzarDado(6);
  Serial.print("Resultado del dado: ");
  Serial.println(resultado);
}

void loop() {
}
