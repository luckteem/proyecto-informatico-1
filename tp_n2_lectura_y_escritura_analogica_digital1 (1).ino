const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;
const int buzzerPin = 9;
const int buttonPin = 2;

const int potTime = A0;
const int potRed = A1;
const int potGreen = A2;
const int potBlue = A3;

int secuenciaActiva = 1;   // controla si la secuencia corre o no
int lastButtonState = LOW; // estado previo del botón
int currentButtonState = LOW; // estado actual del botón
int tiempoCambio = 1000;   // tiempo entre cambios de color
int estadoColor = 0;       // no usado aquí, pero preparado

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600); // salida para monitorear valores
}

void loop() {
  // leer botón y alternar secuencia
  currentButtonState = digitalRead(buttonPin);
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    if (secuenciaActiva == 1) {
      secuenciaActiva = 0; // apaga secuencia
    } else {
      secuenciaActiva = 1; // activa secuencia
    }
    delay(200); // evita rebotes
  }
  lastButtonState = currentButtonState;

  // leer potenciómetros y mapear valores
  int valorR = (analogRead(potRed) * 255) / 1023;   // intensidad rojo
  int valorG = (analogRead(potGreen) * 255) / 1023; // intensidad verde
  int valorB = (analogRead(potBlue) * 255) / 1023;  // intensidad azul
  int valorTiempo = analogRead(potTime);            // controla velocidad
  tiempoCambio = map(valorTiempo, 0, 1023, 500, 3000);

  // muestra valores en monitor serie
  Serial.print("Tiempo: ");
  Serial.print(tiempoCambio / 1000.0);
  Serial.println(" s");
  Serial.print("R: "); Serial.println(valorR);
  Serial.print("G: "); Serial.println(valorG);
  Serial.print("B: "); Serial.println(valorB);

  // secuencia de colores si está activa
  if (secuenciaActiva == 1) {
    // rojo
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    digitalWrite(buzzerPin, HIGH); // sonido breve
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(tiempoCambio);
    digitalWrite(redPin, LOW); digitalWrite(greenPin, LOW); digitalWrite(bluePin, LOW);

    // verde
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(tiempoCambio);
    digitalWrite(redPin, LOW); digitalWrite(greenPin, LOW); digitalWrite(bluePin, LOW);

    // azul
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(tiempoCambio);
    digitalWrite(redPin, LOW); digitalWrite(greenPin, LOW); digitalWrite(bluePin, LOW);
  } else {
    // si no está activa, todo apagado
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
}
