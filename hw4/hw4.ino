String test="This is a sentence";

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int  answer=findspace(test,5);
  Serial.println(answer);
}

int findspace(String sentence, int pointer)
{
  int answer[sentence.length()];//the string can have this many instances of a space at most
  for(int j=0;j<sentence.length();j++)
  {
    answer[j]=-1;
  }
  int count=0;
  for (int i=0;i<sentence.length();i++)
  {
    String temp=sentence.substring(i,i+1);
    if (temp==" ")
    {
      answer[count]=i+1;
      count++;
    }
  }
    return answer[pointer-1];
}

