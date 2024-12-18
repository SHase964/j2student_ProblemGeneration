#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand((unsigned)time(NULL));
  int num;
  int *pt;
  printf("num = ");scanf("%d",&num);

  pt = (int *)malloc(sizeof(int)*num);
  printf("(1)\n");
  for(int i=0;i<num;i++){
    pt[i] = rand()%100;
    printf("pt[%d] = %d\n",i,pt[i]);
  }

  printf("\n(2)\n");
  for(int i=num-1;i>=0;i--){
    printf("pt[%d] = %d \n",i,pt[i]);
  }

  printf("\n(3)\n");
  for(int i=0;i<num;i++){
    if(pt[i]%2 == 0)printf("pt[%d] = %d\n",i,pt[i]);
  }
  free(pt);

  return 0;
}
