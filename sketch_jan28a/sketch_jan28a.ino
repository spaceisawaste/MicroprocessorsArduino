void setup()
{
  Serial.begin(9600);
}
 
int count= 0;
float numOutputs = 0;
int k = 1;
 
void loop()
{
  count++;
  int number = random(0,101);
 
  if (number > 10 && number <26)
  {
    numOutputs++;
  }
 
  if (count==100)
  {
    double average = (numOutputs/(100*k));
    average*=100;
    Serial.print("Values between 10 and 25 were generated ");
    Serial.print(average);
    Serial.println("% of the time");
    count=0;
    k++;
  }
  delay(50);
}     
