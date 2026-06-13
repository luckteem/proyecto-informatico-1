// Variables 
const int ledrojo = 3;
const int ledverde = 6;
const int ledazul = 5;
const int sensortemp = A0;  // TMP35 mide temperatura
const int sensorluz = A1;   // LDR mide luz ambiente

// Variables de lectura
int valorluz = 0;
int luz = 0;

void setup()
{
  pinMode(ledrojo, OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(ledazul, OUTPUT);
  pinMode( A0 , INPUT ); // entrada sensor temp
  pinMode( A1 , INPUT ); // entrada sensor luz
  
  Serial.begin(9600); // monitor serie
}

void loop()
{
  float senal = analogRead(A0) * 5.0 / 1024; // convierte lectura a voltaje
  float temp = senal * 100 - 50 ; // fórmula TMP35 para °C
  
  valorluz = analogRead(sensorluz); // lectura cruda LDR
  luz = map(valorluz, 1, 310, 100, 0); // escala a porcentaje
  Serial.println(valorluz); // muestra valor de luz
  
  // solo prende LED si luz entre 30% y 70%
  if(luz >= 30 && luz <= 70)
  {
    // condicional para color según temperatura
    if(temp > 90)
    {
      digitalWrite(ledrojo, HIGH); // rojo si temp muy alta
      digitalWrite(ledverde, LOW);
      digitalWrite(ledazul, LOW);
    }
    else if(temp < 18)
    {
      digitalWrite(ledrojo, LOW);
      digitalWrite(ledverde, LOW);
      digitalWrite(ledazul, HIGH); // azul si temp baja
    }
    else
    {
      digitalWrite(ledrojo, LOW);
      digitalWrite(ledverde, HIGH); // verde si temp normal
      digitalWrite(ledazul, LOW);
    }
  }
  else
  {
    // apaga LED si luz fuera del rango
    digitalWrite(ledrojo, LOW);
    digitalWrite(ledverde, LOW);
    digitalWrite(ledazul, LOW);
  }
  
  delay(500); // pausa entre lecturas
}
