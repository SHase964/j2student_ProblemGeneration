#include <stdio.h>

int main(void)
{
  char i,k,j;
  char text[]="This is a sample sentence.";

  i=0;
  while(text[i]!='\0'){
    i++;
  }
  while(i>-1){
    printf("%c",text[i]);
    i--;
  }
   printf("\n");





  return 0;
}
