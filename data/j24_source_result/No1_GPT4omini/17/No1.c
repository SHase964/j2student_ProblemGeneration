#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

  int array_num;
  int *array;
  int i;
  int *array_2;

  srand((unsigned)time(NULL));
  
  printf("配列の数を入力してください。\n");
  scanf("%d",&array_num);

  array = (int *)malloc(sizeof(int)*array_num);
  array_2 = (int *)malloc(sizeof(int)*array_num);

  printf("before : ");
  for(i=0;i<array_num;i++){
    array[i] = rand()%10;
    printf("%d|",array[i]);
  }
  printf("\n\n");

  printf("after : ");
  for(i=0;i<array_num;i++){
    array_2[i] = array[i]*array[i];
    printf("%d|",array_2[i]);
  }
  printf("\n");
  
  free(array);

  return 0;
}
