#define rojo1 12
#define rojo2 10
#define rojo3 5
#define boton 4
int c=0;
void setup()
{
 
  pinMode(rojo1, OUTPUT);
  pinMode(rojo2, OUTPUT);
  pinMode(rojo3, OUTPUT);
  pinMode(boton, INPUT);
  
}

void loop() 
{
  digitalWrite(rojo1, HIGH);
  digitalWrite(rojo2, HIGH);
  digitalWrite(rojo3, HIGH);
  
 if (digitalRead(boton)== HIGH) 
  { 
   if (c==4)
   {
     c=0;
   }
   c = c+1;
   
   if (c==1)
   {
   while ( digitalRead (boton) == HIGH)
    { 
    digitalWrite(rojo2, LOW);
    digitalWrite(rojo3, LOW);
    }
   }
   else if (c==2)
   {
     while ( digitalRead (boton) == HIGH)
    { 
    digitalWrite(rojo1, LOW);
    digitalWrite(rojo3, LOW);
    }
   }
      else if (c==3)
   {
     while ( digitalRead (boton) == HIGH)
     { 
      digitalWrite(rojo1, LOW);
      digitalWrite(rojo2, LOW);
     }
   }
     if ( digitalRead (boton) == LOW)
     { 
       digitalWrite(rojo1, HIGH);
       digitalWrite(rojo2, HIGH);
       digitalWrite(rojo3, HIGH);
     }
   }   
  }
  