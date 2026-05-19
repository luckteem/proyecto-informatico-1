const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;
const int buzzerPin = 9;
const int buttonPin = 2;

const int potTime = A0;
const int potRed = A1;
const int potGreen = A2;
const int potBlue = A3;

int secuenciaActiva = 1;
int lastButtonState = LOW;
int currentButtonState = LOW;
int tiempoCambio = 1000;
int estadoColor = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Leer botón
  currentButtonState = digitalRead(buttonPin);
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    if (secuenciaActiva == 1) {
      secuenciaActiva = 0;
    } else {
      secuenciaActiva = 1;
    }
    delay(200);
  }
  lastButtonState = currentButtonState;

  // Leer potenciómetros
  int valorR = (analogRead(potRed) * 255) / 1023;
  int valorG = (analogRead(potGreen) * 255) / 1023;
  int valorB = (analogRead(potBlue) * 255) / 1023;
  int valorTiempo = analogRead(potTime);
  tiempoCambio = map(valorTiempo, 0, 1023, 500, 3000);

  Serial.print("Tiempo: ");
  Serial.print(tiempoCambio / 1000.0);
  Serial.println(" s");
  Serial.print("R: "); Serial.println(valorR);
  Serial.print("G: "); Serial.println(valorG);
  Serial.print("B: "); Serial.println(valorB);

  // Secuencia de colores
  if (secuenciaActiva == 1) {
    // Color 1: Rojo
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(tiempoCambio);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);

    // Color 2: Verde
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(tiempoCambio);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);

    // Color 3: Azul
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(tiempoCambio);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  } else {
    // Apagar todo si la secuencia está desactivada
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
}
