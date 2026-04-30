#define peaton1 4
#define peaton2 5
#define speaker 2 
void setup()
{
  pinMode(peaton1, OUTPUT);
  pinMode(peaton2, OUTPUT);
  pinMode(speaker, OUTPUT);
}

void loop()
{
  digitalWrite(peaton1, HIGH);
   digitalWrite(speaker, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
 digitalWrite(peaton1, LOW);
 digitalWrite(speaker, LOW);
 digitalWrite(peaton2, HIGH);
  delay(1000);
  digitalWrite(peaton2, LOW);
}