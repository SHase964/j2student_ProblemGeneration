#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){

  char str1[] = "Kisarazu";
  char str2[] = "Kosen";

  int numstr1 = 0;
  int numstr2 = 0;

  char *str3;

  int i=0;
  while(str1[i]!='\0'){
    numstr1++;
    i++;
  }

  i=0;
  while(str2[i]!='\0'){
    numstr2++;
    i++;
  }

  

  int len = numstr1+numstr2;

  str3 = (char *)malloc(sizeof(char) * len);

  for(int i=0; i<numstr1; i++){
    str3[i] = str1[i];
  }

  for(int i=numstr1; i<numstr1+numstr2; i++){
    str3[i] = str2[i-numstr1];
  }

  printf("str3= ''%s''\n",str3);

  free(str3);

  return 0;
}
