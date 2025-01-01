#include <stdio.h>
#include <stdlib.h>

int kansuu(int x,int *big,int *small,int *y){
  int i;
  *small=y[0];
  *big=y[0];
  for(i=0;i<x;i++){
    if(*big<=y[i]){
      *big=y[i];
    }
    if(*small>=y[i]){
      *small=y[i];
    }
  }
  return 0;
}

int main(){
  int x,i,small,big;
  int *y;

  scanf("%d",&x);
  y =(int *)malloc(sizeof(int)* x);

  for(i=0;i<x;i++){
    scanf("%d",&y[i]);
  }

  kansuu(x,&big,&small,y);
  printf("最小値");
  printf("%d\n",small);
  printf("最大値")
  printf("%d\n",big);

free(y);
}


