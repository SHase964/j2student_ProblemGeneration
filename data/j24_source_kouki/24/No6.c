#include<stdio.h>
#include<stdlib.h>

int main(void){
  char str1[]="Kisarazu";
  char str2[]="City";
  int i,sen[2],sent,flag;
  char *arr;

  for(i=0;i!='\0';i++){
  }
  sen[0]+=i;
  for(i=0;i!='\0';i++){
  }
  sen[1]+=i;
  for(i=0;i<2;i++){
    sent+=sen[i];
  }

  flag=0;
  arr=(char *)malloc(sizeof(char)*(sent+1));
  for(i=0;i<sent;i++){
    if(str1[i]=='\0'&&flag==0){
      flag=1;
    }
    if(flag==0){
      arr[i]=str1[i];
    }
    if(flag==1){
      arr[i]=str2[(i-sen[0])];
    }
    printf("%c",arr[i]);
  }
  printf("\n");
  return 0;
}