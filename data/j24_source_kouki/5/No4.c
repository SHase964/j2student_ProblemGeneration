#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  srand((unsigned)time(NULL));

  int size;
  int *array;

  printf("(1)Enter array size: ");
  scanf("%d", &size);

  array = (int *)malloc(sizeof(int) * size);

  int i;

  for(i = 0; i < size; i++){
    array[i] = rand()%100;

    printf("%2d,", array[i]);
  }
  printf("\n");

  printf("(2)\n");

  for(i = 0; i < size; i++){
    printf("%2d,", array[size - i - 1]);
  }
  printf("\n");

  printf("(3)\n");

  for(i = 0; i < size; i++){
    if(array[i]%2 == 0){
      printf("%2d,", array[i]);
    }
  }
  printf("\n");

  free(array);

  return 0;
}
