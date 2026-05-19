#define r1 11
#define g1 10
#define b1 9   // LED 1 RGB

#define r2 8
#define g2 7
#define b2 6   // LED 2 RGB  

#define r3 5
#define g3 4
#define b3 3   // LED 3 RGB

#define bz 2   // Buzzer

void setup() {
  pinMode(r1, OUTPUT); pinMode(g1, OUTPUT); pinMode(b1, OUTPUT);
  pinMode(r2, OUTPUT); pinMode(g2, OUTPUT); pinMode(b2, OUTPUT);
  pinMode(r3, OUTPUT); pinMode(g3, OUTPUT); pinMode(b3, OUTPUT);
  pinMode(bz, OUTPUT);

  // Apagar todo al inicio
  digitalWrite(r1, LOW); digitalWrite(g1, LOW); digitalWrite(b1, LOW);
  digitalWrite(r2, LOW); digitalWrite(g2, LOW); digitalWrite(b2, LOW);
  digitalWrite(r3, LOW); digitalWrite(g3, LOW); digitalWrite(b3, LOW);
  digitalWrite(bz, LOW);
}

void loop() {
  // LED 1: Rojo
  digitalWrite(r1, HIGH);
  digitalWrite(g1, LOW);
  digitalWrite(b1, LOW);
  delay(1000);

  // Apagar todo
  digitalWrite(r1, LOW); digitalWrite(g1, LOW); digitalWrite(b1, LOW);
  digitalWrite(r2, LOW); digitalWrite(g2, LOW); digitalWrite(b2, LOW);
  digitalWrite(r3, LOW); digitalWrite(g3, LOW); digitalWrite(b3, LOW);

  // Buzzer
  digitalWrite(bz, HIGH);
  delay(80);
  digitalWrite(bz, LOW);

  // LED 2: Violeta (rojo + azul)
  digitalWrite(r2, HIGH);
  digitalWrite(g2, LOW);
  digitalWrite(b2, HIGH);
  delay(1000);

  // Apagar todo
  digitalWrite(r1, LOW); digitalWrite(g1, LOW); digitalWrite(b1, LOW);
  digitalWrite(r2, LOW); digitalWrite(g2, LOW); digitalWrite(b2, LOW);
  digitalWrite(r3, LOW); digitalWrite(g3, LOW); digitalWrite(b3, LOW);

  // Buzzer
  digitalWrite(bz, HIGH);
  delay(80);
  digitalWrite(bz, LOW);

  // LED 3: Celeste (verde + azul)
  digitalWrite(r3, LOW);
  digitalWrite(g3, HIGH);
  digitalWrite(b3, HIGH);
  delay(1000);

  // Apagar todo
  digitalWrite(r1, LOW); digitalWrite(g1, LOW); digitalWrite(b1, LOW);
  digitalWrite(r2, LOW); digitalWrite(g2, LOW); digitalWrite(b2, LOW);
  digitalWrite(r3, LOW); digitalWrite(g3, LOW); digitalWrite(b3, LOW);

  // Buzzer
  digitalWrite(bz, HIGH);
  delay(80);
  digitalWrite(bz, LOW);
}
