#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

  int *array;
  int array_num;
  int i;

  printf("num = ");
  scanf("%d",&array_num);

  array = (int *)malloc(sizeof(int)*array_num);
  srand((unsigned)time(NULL));

  printf("(1)\n");
  for(i=0;i<array_num;i++){
    array[i] = rand()%100;
    printf("%d|",array[i]);
  }
  printf("\n");

  printf("(2)\n");
  for(i=0;i<array_num;i++){
    printf("%d|",array[array_num-(1+i)]);
  }
  printf("\n");

  printf("(3)\n");
  for(i=0;i<array_num;i++){
    if(array[i]%2==0){
      printf("%d|",array[i]);
    }
  }
  printf("\n");

  free(array);
  
  return 0;
}
