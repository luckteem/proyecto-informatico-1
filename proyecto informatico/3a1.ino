void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A1, OUTPUT);
}

void loop()
{
  
  for (int i = 0; i < 50; i++) {
  	digitalWrite( 3 , HIGH);
    tone( A1 , 440 );
  	delay(700);
  	digitalWrite( 3 , LOW);
  	digitalWrite ( 4 , HIGH );
    tone( A1 , 880 );
  	delay (700);
  	digitalWrite ( 4 , LOW );
  }  
}