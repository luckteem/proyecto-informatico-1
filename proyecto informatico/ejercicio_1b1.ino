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
  delay(1000);
 digitalWrite(uno, HIGH);
  delay(1000); 
 digitalWrite(dos, HIGH);
  delay(1000); 
 digitalWrite(tres, HIGH);
  delay(1000); 
 digitalWrite(cuatro, HIGH);
  delay(1000); 
 digitalWrite(cinco, HIGH);
  delay(1000);
 digitalWrite(seis, HIGH);
  delay(1000); 
 digitalWrite(siete, HIGH);
  delay(1000); 
 digitalWrite(ocho, HIGH);
  delay(1000);
 digitalWrite(nueve, HIGH);
  delay(1000);  
 digitalWrite(diez, HIGH);
   delay(1000);
   
 digitalWrite(uno, LOW);
 digitalWrite(dos, LOW);
 digitalWrite(tres, LOW);
 digitalWrite(cuatro, LOW);
 digitalWrite(cinco, LOW);
 digitalWrite(seis, LOW);
 digitalWrite(siete, LOW);
 digitalWrite(ocho, LOW);
 digitalWrite(nueve, LOW);
 digitalWrite(diez, LOW);
 delay(500);
}