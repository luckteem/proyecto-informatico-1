// Variables 
const int ledrojo = 3;
const int ledverde = 6;
const int ledazul = 5;
const int sensortemp = A0;  // TMP35
const int sensorluz = A1;   // LDR

// Variables de lectura
int valorluz = 0;
int luz = 0;

void setup()
{
  pinMode(ledrojo, OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(ledazul, OUTPUT);
  pinMode( A0 , INPUT );
  pinMode( A1 , INPUT );
  
  Serial.begin(9600);
}

void loop()
{
  float senal = analogRead(A0) * 5.0 / 1024;
  float temp = senal * 100 - 50 ; //corrigió la formula, en vez de dividido es *
  
  valorluz = analogRead(sensorluz);
  luz = map(valorluz, 1, 310, 100, 0);
  Serial.println(valorluz);//añadio esto pq no lo leia
// solo prende la led si la luz está entre 30% y 70%
  if(luz >= 30 && luz <= 70)
  {
    // Condicional compuesto para color del LED
    if(temp > 90)
    {
      digitalWrite(ledrojo, HIGH);
      digitalWrite(ledverde, LOW);
      digitalWrite(ledazul, LOW);
    }
    else if(temp < 18)
    {
      digitalWrite(ledrojo, LOW);
      digitalWrite(ledverde, LOW);
      digitalWrite(ledazul, HIGH);
    }
    else
    {
      digitalWrite(ledrojo, LOW);
      digitalWrite(ledverde, HIGH);
      digitalWrite(ledazul, LOW);
    }
  }
  else
  {
    digitalWrite(ledrojo, LOW);
    digitalWrite(ledverde, LOW);
    digitalWrite(ledazul, LOW);
  }
  
  delay(500);
}
