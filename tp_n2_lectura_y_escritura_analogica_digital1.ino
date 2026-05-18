const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;
const int buzzerPin = 9;
const int buttonPin = 2;

const int potTime = A0;
const int potRed = A1;
const int potGreen = A2;
const int potBlue = A3;

bool secuenciaActiva = true;
bool lastButtonState = LOW;
bool currentButtonState;

unsigned long lastChange = 0;
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

void setColor(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

void loop() {
  currentButtonState = digitalRead(buttonPin);
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    secuenciaActiva = !secuenciaActiva;
    delay(200);
  }
  lastButtonState = currentButtonState;

  int valorR = (analogRead(potRed) * 255.0) / 1023.0;
  int valorG = (analogRead(potGreen) * 255.0) / 1023.0;
  int valorB = (analogRead(potBlue) * 255.0) / 1023.0;

  int valorTiempo = analogRead(potTime);
  tiempoCambio = map(valorTiempo, 0, 1023, 0, 3000);

  Serial.print("Tiempo: ");
  Serial.print(tiempoCambio / 1000.0);
  Serial.println(" s");
  Serial.print("R:"); Serial.println(valorR);
  Serial.print("G:"); Serial.println(valorG);
  Serial.print("B:"); Serial.println(valorB);

  if (secuenciaActiva) {
    unsigned long ahora = millis();
    if (ahora - lastChange >= tiempoCambio) {
      estadoColor++;
      if (estadoColor > 2) estadoColor = 0;

      tone(buzzerPin, 1000, 100);
      delay(100);
      noTone(buzzerPin);

      setColor(0, 0, 0);
      delay(100);

      if (estadoColor == 0) {
        setColor(valorR, 0, 0);
      } else if (estadoColor == 1) {
        setColor(0, valorG, 0);
      } else if (estadoColor == 2) {
        setColor(0, 0, valorB);
      }
      lastChange = ahora;
    }
  } else {
    setColor(0, 0, 0);
    noTone(buzzerPin);
  }
}
