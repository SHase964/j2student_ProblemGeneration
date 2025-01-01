#include <stdlib.h>
#include <stdio.h>


int main(void){

  int *pt;
  int i,a,b,c;
  int dummy;
  int total;


  scanf("%d",&a);

  pt=(int *)malloc(sizeof(int)*a);

  total=0;
  for(i=0;i<a;i++){
    scanf("%d,%d",&pt[i],dummy);
    total=total+pt[i];
  }

  c=total/a;
  printf("中央値は%dです",c);

  free(pt);
  return 0;
}  
