#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  srand((unsigned)time(NULL));
  
  int n;
  scanf("%d", &n);

  int **matrix;
  matrix = malloc(sizeof(int *) * n);
  for(int i = 0; i < n; i++) {
    matrix[i] = malloc(sizeof(int) * n);
  }

  printf("\n(1)\n");
  for(int i = 0; i < n; i++) {

    for(int j = 0; j < n; j++) {
      matrix[i][j] = rand() % 10;
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  printf("\n(2)\n");
  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += matrix[i][i];
  }
  printf("%d\n", sum);

  printf("\n(3)\n");
  for(int i = 0; i < n; i++) {

    for(int j = 0; i + j < n; j++) {
      int store;
      store = matrix[i][i + j];
      matrix[i][i + j] = matrix[i + j][i];
      matrix[i + j][i] = store;
    }
  }
  for(int i = 0; i < n; i++) {

    for(int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  
  for(int i = 0; i < n; i++) {
    free(matrix[i]);
  }
  free(matrix);
  
  return 0;
}
