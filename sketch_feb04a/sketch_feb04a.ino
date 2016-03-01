const int potPin=2;
const int motorPin=9;
int voltage=0;
void setup()
{
  Serial.begin(9600);
  pinMode(motorPin,OUTPUT);
  pinMode(potPin,OUTPUT);
}

void loop()
{
  voltage=analogRead(A0);
  int  pwmRange=map(voltage,0,1023,0,255);

  Serial.println(voltage);
  delay(100);
  analogWrite(motorPin,pwmRange);
}
