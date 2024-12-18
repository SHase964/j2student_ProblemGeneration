#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

  int **array;
  int array_n;
  int i,j;
  int sum;

  printf("n = ");
  scanf("%d",&array_n);

  array = (int **)malloc(sizeof(int *)*array_n);
  srand((unsigned)time(NULL));

  sum = 0;
  printf("(1)\n");
  for(i=0;i<array_n;i++){
    array[i] = (int *)malloc(sizeof(int)*array_n);
    for(j=0;j<array_n;j++){
      array[i][j] = rand()%10;
      printf("%d ",array[i][j]);
      if(i==j){
	sum += array[i][j];
      }
    }
    printf("\n");
  }
  printf("(2)\nsum = %d\n",sum);

  printf("(3)\n");
  for(i=0;i<array_n;i++){
    for(j=0;j<array_n;j++){
      array[i][j] = array[j][i];
      printf("%d ",array[i][j]);
    }
    printf("\n");
  }

  for(i=0;i<array_n;i++){
    free(array[i]);
  }
  free(array);

  return 0;
}
      
