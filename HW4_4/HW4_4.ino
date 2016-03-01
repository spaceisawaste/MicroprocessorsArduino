void setup() {
  Serial.begin(9600); //start serial monitor output
}

void loop() {
  String test="We shall always place education side by side with instruction; the mind will not be cultivated at the expense of the heart. While we prepare useful citizens for society, we shall likewise do our utmost to prepare citizens for heaven.";
  int a=0; //start index for substrig
  String temp=""; //placeholder for manipulating the substring
  
  for (int count=1;count<500;count++)
  {
   int b=findspace(test,count); //stop index for substring
   if(b>0)
   {
   temp=test.substring(a,b); //this string is one word of the sentence
   Serial.println(temp);
   a=b;
   }
   else //prints the final word of the sentence
   {
    temp=test.substring(a);
    Serial.println(temp);
    break; //we only need this to happen once, so we break out of the for loop once its done. A more elegant solution would be to use a boolean and && in the for() condition that we then modify here
   }
  }
  while(1==1); //stops loop() from doing this continuously
}

/*
 * This function finds the indices of spaces in a given string that is 500 char or less in length and returns the position of the space indicated by pointer.
 * Returns the location of the space indicated by pointer, or -1 if no such space exists. 
 */
int findspace(String sentence, int pointer)
{
  if(sentence.length()>500) //enforces a 500 character limit
  {
    return -1;
  }
  int answer[sentence.length()];//the string can have this many instances of a space at most. We will overwrite the zeroes in instances where spaces exist
  
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
      answer[count]=i+1;  //had to do some tweaking since Strings are 0 up, but we are assuming a start index of 1. This will actually be kinda convenient later when we use it to break a sentence up, since it gives us a stop index of 1 past the space, which is how substring() works.
      count++;
    }
  }
    return answer[pointer-1];
}

 
