#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int num;
  int **array;
  
  printf("num = ");
  scanf("%d",&num);

  array = (int **)malloc(sizeof(int*)*num);
  for(int i=0; i <num; i++){
    array[i] = (int *)malloc(sizeof(int)*num);
  }
  srand((unsigned)time(NULL));
  
  printf("(1)\n");
  for(int i=0; i<num; i++){
    for(int j=0; j<num; j++){
      array[i][j] = rand()%10;
      printf("%d ",array[i][j]);
    }
    printf("\n");
  }
  printf("(2)\n");
  int total = 0;
  for(int i=0; i<num; i++){
    total = total + array[i][i];
  }
  printf("%d\n",total);
  printf("(3)\n");
  int **save;
  save = (int **)malloc(sizeof(int*)*num);
  for(int i=0; i <num; i++){
    save[i] = (int *)malloc(sizeof(int)*num);
  }

  for(int i=0; i<num; i++){
    for(int j=0; j<num; j++){
      save[i][j]  = array[i][j];
    }
  }
  for(int i=0; i<num; i++){
    for(int j=0; j<num; j++){
      array[i][j] = save[j][i];
      printf("%d ",array[i][j]);
    }
    printf("\n");
  }

  free(array);   free(save);
  return 0;
}
