#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int i,j;
  int array_num;
  int **array;
  int **tarray;
  int sum = 0;

  printf("input_num = ");
  scanf("%d", &array_num);

  srand((unsigned)time(NULL));
  array = (int**)calloc(array_num, sizeof(int*));

  for(i = 0; i < array_num; i++){
    array[i] = (int*)calloc(array_num, sizeof(int));
      
    for(j = 0; j < array_num; j++){
       array[i][j] = rand() % 10;
      
    }
  }

  printf("(1)\n");
  for(i = 0; i < array_num; i++){
      printf("|");
    for(j = 0; j < array_num; j++){
      printf("%d", array[i][j]);
    }
    printf("|\n");
  }

  printf("\n(2)\n");
  for(i = 0; i < array_num; i++){
    sum += array[i][i];
  }
  printf("sum = %d\n", sum);

  
  printf("\n(3)\n");

  tarray = (int**)calloc(array_num, sizeof(int*));
  
  for(i = 0; i < array_num; i++){
    tarray[i] = (int*)calloc(array_num, sizeof(int));
    for(j = 0; j < array_num; j++){
      tarray[i][j] = array[j][i];
    }
  }

  for(i = 0; i < array_num; i++){
      printf("|");
    for(j = 0; j < array_num; j++){
      array[i][j] = tarray[i][j];
      printf("%d", array[i][j]);
    }
    printf("|\n");
  }

  //free
  for(i = 0; i < array_num; i++){
    free(array[i]);
  }
  free(array);
  
  return 0;
}
