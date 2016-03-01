/*
 * This function finds the indices of spaces in a given string that is 500 char or less in length and returns the position of the space indicated by pointer.
 * Returns the location of the space indicated by pointer, or -1 if no such space exists. 
 */
int findspace(String sentence, int pointer)
{
  //this is my very brute force method of enforcing a 500 char limit
  if(sentence.length()>500)
  {
    return -1
  }
  
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
      answer[count]=i+1;  //had to do some tweaking since arrays are 0 up
      count++;
    }
  }
    return answer[pointer-1];
}

