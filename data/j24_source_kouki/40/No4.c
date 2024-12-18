#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  int x,i;
  int *num;
  srand((unsigned)time(NULL));

  scanf("%d",&x);
  num=(int *)malloc(sizeof(int)* x);

  printf("(1)\n");
  for(i=0;i<x;i++){
    num[i]=rand()%100;
    printf("%d\n",num[i]);
  }

  printf("(2)\n");
  for(i=x;i>0;i--){
    printf("%d\n",num[i-1]);
  }

  printf("(3)\n");
  for(i=0;i<x;i++){
    if(num[i]%2==0){
      printf("%d\n",num[i]);
    }
  }
  free(num);
}
