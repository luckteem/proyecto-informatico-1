#define verde1 6 
#define azul1 7
#define rojo1 8
#define verde2 11
#define azul2 12
#define rojo2 13

void setup()
{
  pinMode(verde1, OUTPUT);
  pinMode(azul1, OUTPUT);
  pinMode(rojo1, OUTPUT);
  pinMode(verde2, OUTPUT);
  pinMode(azul2, OUTPUT);
  pinMode(rojo2, OUTPUT);
}

void loop()
{
  digitalWrite(rojo1, HIGH);
  delay(200); // Wait for 1000 millisecond(s)
  digitalWrite(rojo1, LOW);
   digitalWrite(azul1, HIGH);
   digitalWrite(verde1, HIGH);
  delay(200); 
 digitalWrite(azul1, LOW);
   digitalWrite(verde1, LOW);
   digitalWrite(verde1, HIGH); 
  delay(200);
  digitalWrite(verde1, LOW);
   digitalWrite(rojo1, HIGH);
   digitalWrite(azul1, HIGH);
  delay(200); 
  digitalWrite(rojo1, LOW);
   digitalWrite(azul1, LOW);
   digitalWrite(azul1, HIGH);
  delay(200); 
  digitalWrite(azul1, LOW);
   digitalWrite(azul1, HIGH);
   digitalWrite(verde1, HIGH);
  digitalWrite(rojo1, HIGH);
  delay(200); 
  digitalWrite(azul1, LOW);
   digitalWrite(verde1, LOW);
   digitalWrite(rojo1, LOW);
   digitalWrite(verde1, HIGH);
  digitalWrite(rojo1, HIGH);
  delay(200);
  digitalWrite(verde1, LOW);
   digitalWrite(rojo1, LOW);
  
  
  
  //
  
  
  
  digitalWrite(rojo2, HIGH);
  delay(200); // Wait for 1000 millisecond(s)
  digitalWrite(rojo2, LOW);
   digitalWrite(azul2, HIGH);
   digitalWrite(verde2, HIGH);
  delay(200); 
 digitalWrite(azul2, LOW);
   digitalWrite(verde2, LOW);
   digitalWrite(verde2, HIGH); 
  delay(200);
  digitalWrite(verde2, LOW);
   digitalWrite(rojo2, HIGH);
   digitalWrite(azul2, HIGH);
  delay(200); 
  digitalWrite(rojo2, LOW);
   digitalWrite(azul2, LOW);
   digitalWrite(azul2, HIGH);
  delay(200); 
  digitalWrite(azul2, LOW);
   digitalWrite(azul2, HIGH);
   digitalWrite(verde2, HIGH);
  digitalWrite(rojo2, HIGH);
  delay(200); //espaciooooo
  digitalWrite(azul2, LOW);
   digitalWrite(verde2, LOW);
   digitalWrite(rojo2, LOW);
   digitalWrite(verde2, HIGH);
  digitalWrite(rojo2, HIGH);
  delay(200);
  digitalWrite(verde2, LOW);
   digitalWrite(rojo2, LOW);
}