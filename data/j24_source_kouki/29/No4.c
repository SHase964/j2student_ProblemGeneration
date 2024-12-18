#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  printf("(1)\n");

  int in;
  printf("input:");
  scanf("%d",&in);

  int *array,*rev;
  srand((unsigned)time(NULL));

  array=(int*)malloc(sizeof(int)*in);
  rev=(int*)malloc(sizeof(int)*in);

  for(int i=0;i<in;i++){
    array[i]=rand()%100;
    printf("array[%d]=%d\n",i,array[i]);
  }

  printf("(2)\n");

  for(int i=0;i<in;i++){
    rev[i]=array[in-i-1];
    printf("rev[%d]=%d\n",i,rev[i]);
  }

  printf("(3)\n");

  for(int i=0;i<in;i++){
    if(array[i]%2==0) printf("array[%d]=%d\n",i,array[i]);
  }

  free(array);
  free(rev);

}
