#include<stdio.h>
#include<stdlib.h>

int main(void){
  char *str1="kisarazu";
  char *str2="City";
  char **mix;
  int num1,num2,i,j;
  num1=num2=i=j=0;
  while(str1[num1]!='\0'){
    num1++;
  }
  
  while(str2[num2]!='\0'){
    num2++;
  }
  
  mix=(char **)malloc(sizeof(char *)*2);

  mix[0]=(char *)malloc(sizeof(char)*num1);
  mix[1]=(char *)malloc(sizeof(char)*num2);
   


  printf("%s",str1);
  printf("%s\n",str2);

  free(mix[0]);
  free(mix[1]);
  free(mix);
  return 0;
}
