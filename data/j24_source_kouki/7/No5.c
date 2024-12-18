#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int **array;

  int i,j,num,num2;
  num2=0;

  srand((unsigned)time(NULL));
  
  printf("n行n列の正方行列を製作します。\nnに当てはまる数値を入力してください->");
  scanf("%d",&num);

  array = (int **)malloc(sizeof(int *) * num);

  for(i=0;i<num;i++){
    array[i] = (int *)malloc(sizeof(int) * num);
  }

  printf("(1)\n");
  for(i=0;i<num;i++){
    printf("|");
    for(j=0;j<num;j++){
      array[i][j]=rand()%10;
      printf("%d ",array[i][j]);
    }
    printf("|\n");
  }

  printf("(2)\n");
  for(i=0;i<num;i++){
    num2=num2+array[i][i];
  }
  printf("%d\n",num2);

  for(i=0;i<num;i++){
    free(array[i]);
  }
  free(array);

  return 0;
}
