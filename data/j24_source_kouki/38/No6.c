#include <stdio.h>
#include <stdlib.h>

int main(void){

  char str1[]="Kisarazu";
  char str2[]="City";
  char *pt;
  char *pt2;
  int i,total,total2;;

  i=0;
  total=0;
  while(str1[i]!='\0'){
    total=total+1;
    i=i+1;
  }
  printf("%d",total);

  i=0;
  total2=0;
  while(str2[i]!='\0'){
    total2=total2+1;
    i=i+1;
  }

  pt=(char *)malloc(sizeof(char)*total+1);
  pt2=(char *)malloc(sizeof(char)*total2+1);

  pt=str1;
  pt2=str2;

  printf("%s",pt);
  printf("%s",pt2);

  free(pt);
  free(pt2);

  return 0;
}
  
