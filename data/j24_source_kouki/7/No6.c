#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  char str1[]="abcd";
  char str2[]="efghi";

  int i=0;
  int j=0;
  int count=0;

  while(str1[i]!='\0'){
    count++;
    i++;
  }
  i=0;
  while(str2[i]!='\0'){
    count++;
    i++;
  }

  char *str;

  str = (char *)malloc(sizeof(char) * (count+1));

  i=0;
  while(str1[i]!='\0'){
    str[i]=str1[i];
    i++;
  }
  while(str2[j]!='\0'){
    str[i]=str2[j];
    i++;
    j++;
  }

  str[i]='\0';

  printf("%s\n",str);

  free(str);

  return 0;
}