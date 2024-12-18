#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_num(int **array, int n);
void sum_taikaku(int **array, int n);
void tenchi_gyouretu(int **array,int **copy,int n);

int main(void){
  int **array;
  int **copy;
  int n;

  printf("(1)\n");
  printf("enter the num : ");
  scanf("%d",&n);

  array = (int **)malloc(sizeof(int *) * n);
  for(int i = 0;i < n;i++){
    array[i] = (int *)malloc(sizeof(int) * n);
  }
  rand_num(array,n);
   /*--------------------------------------------------------*/
  
  printf("(2)\n");
  sum_taikaku(array, n);
  
  /*--------------------------------------------------------*/
  
  printf("(3)\n");
  copy = (int **)malloc(sizeof(int *) * n);
  for(int i = 0;i < n;i++){
    copy[i] = (int *)malloc(sizeof(int) * n);
  }

  tenchi_gyouretu(array,copy,n);

   /*--------------------------------------------------------*/
  
  for(int i = 0;i < n;i++){
    free(array[i]);
    free(copy[i]);
  }
  free(array);
  free(copy);

  return 0;
}

void rand_num(int **array, int n){
  srand((unsigned)time(NULL));
  
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      array[i][j] = rand() % 10;
      printf("%d ",array[i][j]);
    }
    printf("\n");
  }
}

void sum_taikaku(int **array, int n){
  int taikaku;
  
  for(int i = 0;i < n;i++){
    taikaku += array[i][i];
  }
  printf("taikaku sum : %d\n",taikaku);
}

void tenchi_gyouretu(int **array,int **copy,int n){
  printf("tenchi gyouretu : \n");
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      copy[i][j] = array[j][i];
      array[j][i] = 0;
    }
  }
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      array[i][j] = copy[i][j];
      printf("%d ",array[i][j]);
    }
    printf("\n");
  }
}
