#include<stdio.h>
#include<stdlib.h>


int main(){
  char str1[]="Kisarazu";
  char str2[]="City";
  int count;
  char *pt;

  while(str1[i]!=\0){
    count++;
  }
  while(str2[i]!=\0){
    count++;
  }

  pt=(char *)malloc(sizeof(char)*(count-1));
    


  pt=str1;
  pt[9]=str2;

  free(pt);


  
