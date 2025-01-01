#include <stdio.h>
#include <stdlib.h>

int main(){

  int i = 0, j;
  int tmp;
  int *array;
  int *array_tmp;

  while(1){
    array = (int *)malloc((i + 1) * sizeof(int));
    if(i != 0){
      for(j = 0; j < i; j++){
        array_tmp[i] = array[i];
      }
    }
    free(array);
    scanf("%d", &tmp);
    if(tmp < 0){
      break;
    }
    array_tmp = (int *)malloc((i + 1) * sizeof(int));
    array_tmp[i + 1] = tmp;

    for(j = 0; j <= i; j++){
      array[i] = array_tmp[i];
    }
    free(array_tmp);

    i++;
  }

  for(j = 0; j < i; j++){
    printf("%d\n", array[i]);
  }

  int sum = 0;

  for(j = 0; j < i; j++){
    sum += array[i];
  }

  printf("Average: %lf\n", (double)sum/i);

  return 0;
}
