#define uno 0
#define dos 2
#define tres 3
#define cuatro 4 
#define cinco 5
#define seis 6
#define siete 7
#define ocho 8 
#define nueve 9
#define diez 10
void setup()
{
  pinMode(uno, OUTPUT);
  pinMode(dos, OUTPUT);
  pinMode(tres, OUTPUT);
  pinMode(cuatro, OUTPUT);
  pinMode(cinco, OUTPUT);
  pinMode(seis, OUTPUT);
  pinMode(siete, OUTPUT);
  pinMode(ocho, OUTPUT);
  pinMode(nueve, OUTPUT);
  pinMode(diez, OUTPUT);
}

void loop()
{
 digitalWrite(uno, HIGH);
 digitalWrite(tres, HIGH); 
 digitalWrite(cinco, HIGH);
 digitalWrite(siete, HIGH);
 digitalWrite(nueve, HIGH);
  delay(500);  
 
 digitalWrite(uno, LOW)
 digitalWrite(tres, LOW); 
 digitalWrite(cinco, LOW);
 digitalWrite(siete, LOW);
 digitalWrite(nueve, LOW);
  
  delay(500); 
  
 digitalWrite(dos, HIGH);
 digitalWrite(cuatro, HIGH);
 digitalWrite(seis, HIGH);
 digitalWrite(ocho, HIGH);
 digitalWrite(diez, HIGH);
 delay(500);
  
  
 digitalWrite(dos, LOW);
 digitalWrite(cuatro, LOW);
 digitalWrite(seis, LOW);
 digitalWrite(ocho, LOW);
 digitalWrite(diez, LOW);
 delay(500);
}