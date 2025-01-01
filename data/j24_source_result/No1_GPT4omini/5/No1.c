#include <stdio.h>
#include <stdlib.h>

int main(){
  int size;

  printf("Enter array size: ");
  scanf("%d", &size);

  int *array = (int *)malloc(size * sizeof(int));

  printf("address = %p", array);

  int i;
  char dumy;

  printf("Input array number:\n");
  for(i = 0; i < size; i++){
    scanf("%d", array[i]);
  }

  int max_tmp = 0;
  int min_tmp = 2100000000;

  //calculate max, main
  for(i = 0; i < size; i++){
    if (array[i] >= max_tmp) {
      max_tmp = array[i];
    }
    if (array[i] <= min_tmp){
      min_tmp = array[i];
    }
  }

  printf("Max: %d\n", max_tmp);
  printf("Min: %d\n", min_tmp);
  printf("Difference: %d\n", max_tmp - min_tmp);

  free(array);
}
