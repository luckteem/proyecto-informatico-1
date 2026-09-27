void configurarPines(int entradas[], int cantEntradas, int salidas[], int cantSalidas) {
  for (int i = 0; i < cantEntradas; i++) {
    pinMode(entradas[i], INPUT);
  }
  for (int i = 0; i < cantSalidas; i++) {
    pinMode(salidas[i], OUTPUT);
  }
}

void setup() {
  int pinesEntrada[] = {2, 3};
  int pinesSalida[] = {4, 5, 6};
  configurarPines(pinesEntrada, 2, pinesSalida, 3);
}

void loop() {
}
