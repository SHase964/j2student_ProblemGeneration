#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void m_init(int ***p_matrix, int *size);
void rand_matrix(int ***p_matrix, int size);

int main(){

  int **matrix;
  int size;

  srand((unsigned)time(NULL));

  m_init(&matrix, &size);

  printf("%p\n", &matrix);
  printf("%p\n", matrix);//swap datta...

  rand_matrix(&matrix, size);

  free(matrix);

  return 0;
}

void m_init(int ***p_matrix, int *size){

  printf("Enter matrix size: ");
  scanf("%d", size);
  printf("size = %d\n", *size);

  *p_matrix = (int **)malloc(sizeof(int *) * *size);
  printf("Done!\n");

  int i;

  for(i = 0; i < *size; i++){
    p_matrix[i] = (int **)malloc(sizeof(int *) * *size);
  }
  printf("Done!\n");

}

void rand_matrix(int ***p_matrix, int size){
  printf("rand_matrix action\n");

  int i, j;

  for(i = 0; i < size -1; i++){
    for(j = 0; j < size -1; j++){
      printf("a");
      *p_matrix[i][j] = rand()%10;
      printf("%d ", *p_matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");

}
