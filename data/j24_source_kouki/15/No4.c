#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int *array;
  int array_num;
  int i;
  srand((unsigned)time(NULL));

  printf("input num = ");
  scanf("%d",&array_num);

  array = (int*)calloc(array_num, sizeof(int));

  for(i = 0; i < array_num; i++){
    array[i] = rand() % 100;
  }

  printf("(1)\n");
  for(i = 0; i < array_num; i++){
    printf("[%d] = %d\n", i, array[i]);
  }

  printf("\n(2)\n");
  for(i = array_num -1; i >= 0; i--){
    printf("[%d] = %d\n", i, array[i]);
  }
  
  printf("\n(3)\n");
  for(i = 0; i < array_num; i++){
    if(array[i] % 2 == 0){
      printf("[%d] = %d\n", i, array[i]);
    }
  }
  
  free(array);
  return 0;
}
