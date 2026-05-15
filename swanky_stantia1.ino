// Proyecto: Sistema de medición de distancia con alarma visual y sonora
// Componentes: Sensor ultrasónico HC-SR04, LED RGB, buzzer, botón pulsador
// Funcionalidad: Medir distancia y activar alarmas según proximidad

// --- Definición de pines ---
const int trigPin = 9;       // Pin TRIG del sensor ultrasónico
const int echoPin = 10;      // Pin ECHO del sensor ultrasónico
const int buzzerPin = 6;     // Pin del buzzer
const int buttonPin = 2;     // Pin del botón pulsador

// LED RGB (cada color en un pin distinto)
const int redPin = 3;
const int greenPin = 4;
const int bluePin = 5;

// --- Variables de control ---
bool alarmaActiva = true;    // Estado inicial de la alarma (activada)
bool lastButtonState = LOW;  // Estado anterior del botón
bool currentButtonState;     // Estado actual del botón

long duration;               // Tiempo de eco del sensor
int distance;                // Distancia calculada en cm

// --- Configuración inicial ---
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600); // Comunicación con el Monitor Serial
}

// --- Función para medir distancia ---
int medirDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Fórmula para convertir tiempo en distancia (cm)
  return distance;
}

// --- Función para controlar el LED RGB ---
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

// --- Loop principal ---
void loop() {
  // Leer distancia
  int distanciaActual = medirDistancia();

  // Leer botón para alternar estado de alarma
  currentButtonState = digitalRead(buttonPin);
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    alarmaActiva = !alarmaActiva; // Cambia estado al presionar
    delay(200); // Anti-rebote
  }
  lastButtonState = currentButtonState;

  // Mostrar información en Monitor Serial
  Serial.print("Distancia actual del objeto: ");
  Serial.print(distanciaActual);
  Serial.print(" cm | Estado alarma: ");
  if (alarmaActiva) {
    Serial.println("Activada");
  } else {
    Serial.println("Desactivada");
  }

  // --- Control de alarmas ---
  if (!alarmaActiva) {
    // Alarma desactivada: LED azul, buzzer apagado
    setColor(0, 0, 255);
    noTone(buzzerPin);
  } else {
    // Alarma activada: depende de la distancia
    if (distanciaActual > 150) {
      // Estado 1: zona segura
      setColor(0, 255, 0); // Verde
      noTone(buzzerPin);
    } else if (distanciaActual > 50 && distanciaActual <= 150) {
      // Estado 2: precaución
      setColor(255, 165, 0); // Naranja (rojo+verde)
      tone(buzzerPin, 1000); // Pitido audible
      delay(500);            // Pitido lento cada 500 ms
      noTone(buzzerPin);
      delay(500);
    } else if (distanciaActual <= 50) {
      // Estado 3: peligro
      setColor(255, 0, 0);   // Rojo
      tone(buzzerPin, 1000); // Pitido audible
      delay(50);             // Pitido rápido cada 50 ms
      noTone(buzzerPin);
      delay(50);
    }
  }
}
