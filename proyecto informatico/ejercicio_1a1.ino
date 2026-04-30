
#define rojosemaforoautos  2
#define amarillosemaforoautos 4
#define verdesemaforoautos 7 
#define rojosemaforopeaton 8
#define blancosemaforopeaton 12

void setup()
{
  pinMode(  rojosemaforoautos  , OUTPUT);
  pinMode( amarillosemaforoautos , OUTPUT);
  pinMode( verdesemaforoautos , OUTPUT);
  pinMode(  rojosemaforopeaton , OUTPUT);
  pinMode(  blancosemaforopeaton , OUTPUT);
}

void loop()
{
  digitalWrite( rojosemaforoautos, HIGH);
  digitalWrite( rojosemaforopeaton, HIGH);
  delay(3000);
  digitalWrite( rojosemaforoautos, LOW);
  digitalWrite( rojosemaforopeaton, LOW);
  delay(2000);
  digitalWrite(  amarillosemaforoautos, HIGH);
  delay(1000);
  digitalWrite(amarillosemaforoautos, LOW);
  delay(2000);
  digitalWrite( verdesemaforoautos, HIGH);
  digitalWrite(  blancosemaforopeaton , HIGH);
  delay(1000);
  digitalWrite( verdesemaforoautos, LOW);
  digitalWrite(  blancosemaforopeaton , LOW);
 
}