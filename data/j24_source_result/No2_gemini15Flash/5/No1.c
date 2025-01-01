#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3

int main(){

  char **matrix;
  char tmp[255 + 1] = {};

  int i;

  matrix = (char **)malloc(SIZE * sizeof(char *));

  for(i = 0; i < SIZE; i++){
    fgets(tmp, 255 + 1, stdin);

    matrix[i] = (char *)malloc(strlen(tmp) * sizeof(char) + 1);
    strcpy(matrix[i], tmp);
  }

  for(i = 0; i < SIZE; i++){
    printf("%s", matrix[i]);
    //printf("%d\n", strlen(matrix[i]));
  }

  return 0;
}
