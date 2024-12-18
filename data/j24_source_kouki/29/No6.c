#include <stdio.h>
#include <stdlib.h>

int main(){

  char str1[]="Kisarazu";
  char str2[]="City";

  char *str;
  int len1,len2;

  for(len1=0;str1[len1]!='\0';len1++);
  for(len2=0;str2[len2]!='\0';len2++);
  printf("len1=%d,len2=%d\n",len1,len2);

  str=(char*)malloc(sizeof(char)*(len1+len2+1));

  for(int i=0;i<=len1+len2;i++){
    if(i<len1) str[i]=str1[i];
    else if(i<len1+len2) str[i]=str2[i-len1];
    else str[i]='\0';
  }
  printf("str=%s\n",str);

}
