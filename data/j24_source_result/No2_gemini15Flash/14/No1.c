#include<stdio.h>
#include<stdlib.h>

int main(void){
  char *pt,dummy;
  int i;
  i=0;

  pt = (char *)malloc(sizeof(char)*10+1);
  while(i<10){
    scanf("%c",&pt[i]);
    scanf("%c",&dummy);
    if(pt[i]<"10"){
      i++;
    }
  }
  printf("入力:%s\n",pt);
  free(pt);
  return 0;
}
  
