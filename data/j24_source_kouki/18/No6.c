#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void main(){


  char str1[]="Kisarazu", str2[]="City", *combine;
  int length1, length2, length, i;

  for(length1=0;str1[length1]!='\0';length1++){

  }
  for(length2=0;str2[length2]!='\0';length2++){

  }
  length=0;
  length=length1+length2;
  
  
  combine=(char *)malloc(sizeof(char *)*(length+1));

  for(i=0;i<length;i++){
    if(i<length1){
      combine[i]=str1[i];
    }else{
      combine[i]=str2[i-length1];
    }
  }
  
  combine[length]='\0';
  printf("%s\n", combine);

  free(combine);
}
