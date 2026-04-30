#define boton 4
#define speaker 2
void setup()
{
  pinMode(boton, INPUT);
  pinMode(speaker, OUTPUT);
}

void loop()
{
 if (digitalRead(boton)== HIGH) 
  { 
   digitalWrite(speaker, HIGH);
   delay(600);
   digitalWrite(speaker, LOW);
   delay(600);
   }
}