#define rojo 5
#define azul 3
#define verde 2
#define boton 4
int c=0;
void setup()
{
 
  pinMode(rojo, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(boton, INPUT);
  
}

void loop() 
{ 
 if (digitalRead(boton)== HIGH) 
  { 
   if (c == 8)
   {
     c = 0;
   }
   c = c + 1;
   
   if (c == 1)
   {
   while ( digitalRead (boton) == HIGH)
    { 
    digitalWrite(rojo, HIGH);
    }
   }
   else if (c==2)
   {
     while ( digitalRead (boton) == HIGH)
    { 
    digitalWrite(rojo, LOW);
    digitalWrite(verde, HIGH);
    digitalWrite(azul, HIGH);
    }
   }
      else if (c==3)
   {
     while ( digitalRead (boton) == HIGH)
     { 
      digitalWrite(azul, LOW);
     }
   }
    else if (c==4)
   {
     while ( digitalRead (boton) == HIGH)
    { 
    digitalWrite(rojo, HIGH);
    digitalWrite(verde,LOW);
    digitalWrite(azul, HIGH);
    }
   }
   else if (c==5)
   {
     while ( digitalRead (boton) == HIGH)
    { 
    digitalWrite(rojo, LOW);
 
    }
   }
   else if (c==6)
   {
     while ( digitalRead (boton) == HIGH)
    { 
    digitalWrite(azul, LOW);
    digitalWrite(rojo, HIGH);
    digitalWrite(verde, HIGH);
    }
   }
   else if (c==7)
   {
     while ( digitalRead (boton) == HIGH)
    { 
    digitalWrite(azul, LOW);
    }
   }
   digitalWrite (verde, LOW);
  
   }   
  }
  