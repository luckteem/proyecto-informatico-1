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
  
  apagarTodo();
}

void loop() {

  analogWrite(r1, 255);
  analogWrite(g1, 0);
  analogWrite(b1, 0);
  delay(1000);
  apagarTodo();
  sonarBuzzer();
  
  
  digitalWrite(r2, HIGH);
  digitalWrite(g2, LOW);
  digitalWrite(b2, HIGH);
  delay(1000);
  apagarTodo();
  sonarBuzzer();
 
 
  analogWrite(r3, 0);
  analogWrite(g3, 30);
  analogWrite(b3, 30);
  delay(1000);
  apagarTodo();
  sonarBuzzer();

}


void apagarTodo() {
  analogWrite(r1, 0); analogWrite(g1, 0); analogWrite(b1, 0);
  analogWrite(r2, 0); analogWrite(g2, 0); analogWrite(b2, 0);
  analogWrite(r3, 0); analogWrite(g3, 0); analogWrite(b3, 0);
}

void sonarBuzzer() {
  analogWrite(bz, 150);
  delay(80);
  analogWrite(bz, 0);
}

