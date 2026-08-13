int led1 = 7;  
int led2 = 8;  
int secuencia1[] = {1, 0, 0, 1, 1, 0, 1, 1};  
int secuencia2[] = {0, 1, 0, 1, 0, 0, 1, 0};  
int cantidad = 8;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Iniciando secuencia doble...");
}

void loop() {
  for (int i = 0; i < cantidad; i++) {
    digitalWrite(led1, secuencia1[i] == 1 ? HIGH : LOW);

    digitalWrite(led2, secuencia2[i] == 1 ? HIGH : LOW);

    Serial.print("Paso ");
    Serial.print(i + 1);
    Serial.print(": LED1=");
    Serial.print(secuencia1[i]);
    Serial.print(" | LED2=");
    Serial.println(secuencia2[i]);

    delay(500);  
  }
}
