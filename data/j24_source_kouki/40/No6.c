#include <stdio.h>
#include <stdlib.h>

int main (){

  int i=0,x;
  char *str1="kisarazu";
  char *str2="city";

  while(str1[i]!='\0'){
    i++;
  }
  str1=(char *)malloc(sizeof(char)* i);

  i=0;
  while(str2[i]!='\0'){
    i++;
  }
  str2=(char *)malloc(sizeof(char)* i);
  printf("(1)\n");
  printf("%s",str1);
  printf("%s\n",str2);

  free(str1);
  free(str2);
}
