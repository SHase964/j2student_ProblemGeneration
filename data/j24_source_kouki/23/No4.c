#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){

  int *array;
  int len;

  srand((unsigned)time(NULL));

  printf("type length\n");
  scanf("%d",&len);

  array = (int *)malloc(sizeof(int) * len);

  for(int i=0; i<len; i++){
    array[i] = rand()%100;
  }

  printf("(1)\n");
  for(int i=0; i<len; i++){
    printf("array[%d] = %3d\n",i,array[i] );
  }

  printf("(2)\n");
  for(int i=len-1; i>=0; i--){
    printf("array[%d] = %3d\n",i,array[i] );
  }

  printf("(3)\n");
  for(int i=0; i<len; i++){
    if(array[i]%2 == 0)printf("array[%d] = %3d\n",i,array[i] );
  }

  return 0;
}
