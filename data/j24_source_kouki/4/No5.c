#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int num = 0;
  int **ptpt;
  int sum = 0;
  int **array;

  srand((unsigned)time(NULL));

  while(num <= 0) scanf("%d",&num);

  ptpt = (int **)malloc(sizeof(int *)*num);
  for(int count = 0; count < num; count++) {
    ptpt[count] = (int *)malloc(sizeof(int)*num);
  }

  for(int row = 0; row < num; row++) {
    for(int callum = 0; callum < num; callum++) {
      ptpt[row][callum] = rand()%10; 
    }
  }

  printf("(1)\n");
  for(int row = 0; row < num; row++) {
    for(int callum = 0; callum < num; callum++) {
      //printf("ptpt[%d][%d] = %d\n", row, callum, ptpt[row][callum]);
      printf("%d ", ptpt[row][callum]);
    }
    printf("\n");
  }

  printf("(2)\n");
  for(int count = 0; count < num; count++) sum += ptpt[count][count];
  printf("sum = %d\n", sum);

  array = (int **)malloc(sizeof(int *)*num);
  for(int count = 0; count < num; count++) {
    array[count] = (int *)malloc(sizeof(int)*num);
  }
  for(int row = 0; row < num; row++) {
    for(int callum = 0; callum < num; callum++) {
      array[row][callum] = ptpt[callum][row]; 
    }
  }
  
  printf("(3)\n");
  for(int row = 0; row < num; row++) {
    for(int callum = 0; callum < num; callum++) {
      //printf("ptpt[%d][%d] = %d\n", row, callum, ptpt[row][callum]);
      printf("%d ", array[row][callum]);
    }
    printf("\n");
  }

  free(ptpt);
}
