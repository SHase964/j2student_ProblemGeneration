#include<stdio.h>

int main(void){
  int i,j;
  char sen[10000],wor[10000],dum;
  char *arr;
  printf("input sentence\n");
  scanf("%c",&sen);
  
  i=0;
  j=0;
  while(sen[i]!='\0'){
    wor[j]++;
    if(sen[i]=' '){
      arr=(char)malloc(sizeof(char)*(wor[j]+1));
      j++;
    }
    i++;
  }

  i=0;
  j=0;
  while(sen[i]!='\0'){
    arr[j]=sen[i];
    if(sen[i]=' '){
      j++;
    }
  }
  for(i=0;sen[i]!='\0';i++){
    
  }
  return 0;
}
