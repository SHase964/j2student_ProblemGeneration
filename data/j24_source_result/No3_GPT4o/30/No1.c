#include<stdio.h>
#include<stdlib.h>
#define SIZE 22

int main(void){
  char *s;
  char *res;
  int i=0,j=0,k=0;
  s=(char *)malloc(sizeof(char)*SIZE);
  res=(char *)malloc(sizeof(char)*SIZE);
  fgets(s,SIZE,stdin);
  while(s[i]!='\0'){
    if(s[i]==' '){
      j=i-1;
      while(s[j]!=' ' && j>=0){
	res[k]=s[j];
	j--;
	k++;
      }
      res[k]=' ';
      k++;
    }
    i++;
  }
  j=i-1;
  while(s[j]!=' ' && j>=0){
    res[k]=s[j];
    j--;
    k++;
  }
  res[SIZE-1]='\0';
  printf("%s\n",res);
  free(res);
  free(s);
  return 0;
  
}
