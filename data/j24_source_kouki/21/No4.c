#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  int *pt;
  int num;
  int i;

  printf("数値を入力\n");
  scanf("%d",&num);

  pt = (int *)malloc(sizeof(int)*num);

  srand((unsigned)time(NULL));

  printf("\n(1)\n");
  
  for(i=0;i<num;i++){
    pt[i] = rand()%100;
    printf("pt[%d]に%dを入力\n",i,pt[i]);
  }

  printf("\n(2)\n");
  
  for(i=num;0<i;i--){
    printf("pt[%d] = %d\n",i-1,pt[i-1]);
  }

  printf("\n(3)\n");

  for(i=0;i<num;i++){
    if(pt[i]%2==0){
      printf("pt[%d] = %d\n",i,pt[i]);
    }
  }

  free(pt);

  return 0;
}
