#include<stdio.h>
#include<stdlib.h>
#define SIZE 30


int main(void){
  char *s;
  char *res;
  int i,j,p,k;
  s=(char *)malloc(sizeof(char)*SIZE+1);
  fgets(s,SIZE+1,stdin);
  res=(char *)malloc(sizeof(char)*SIZE+1);
  i=0;
  k=0;
  while(s[i]!='\0'){i++;}
  p=i;
  while(i==0){
    if(s[i]==' '){
      for(j=i+1;j<=p;j++){
	res[k]=s[j];
      }
    }
    i--;
  }
  printf("%s\n",res);

  return 0;
}
