#include <stdio.h>
#include <stdlib.h>

void kannsuu(int x,int *y,int *min,int *max){
  int i;

  for(i=0;i<x;i++){
    if(*max<y[i]){
      *max=y[i];
    }
    if(*min>y[i]){
      *min=y[i];
    }
  }

}


int main () {

  int i,x,max,min;
  int *y;

  scanf("%d",&x);

  y=(int *)malloc(sizeof(int)* x);

  for(i=0;i<x;i++){
    scanf("%d",&y[i]);
  }

  max=y[0];
  min=y[0];

  kannsuu(x,y,&min,&max);

  printf("最大値=%d\n",max);
  printf("最小値=%d\n",min);

  free(y);
}
