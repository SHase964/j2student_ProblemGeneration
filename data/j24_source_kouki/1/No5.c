#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int **numberBox;
  int i;
  int r, c;
  int num;

  srand((unsigned)time(NULL));
  scanf("%d",&num);
  
  // 行数を決める
  numberBox = (int **)malloc(sizeof(int *) * num);
  for (r=0; r<num; r++) {
    numberBox[r] = (int *)malloc(sizeof(int) * num);
  }

  
  for (r=0; r<num; r++) {
    for (c=0; c<num; c++) {
      numberBox[r][c] =  rand()%10;
    }
  }

  printf("\n(1)\n");
  for (r=0; r<num; r++) {
    for (c=0; c<num; c++) {
      printf("%2d",numberBox[r][c]);
    }
    printf("\n");
  }


  
  printf("\n(2)\n");
  int A,sum;
  A=0;
  while(A<num){
    printf("%2d",numberBox[A][A]);
    sum = sum + numberBox[A][A];
    A++;
    printf("\n");
  }
  printf("sum=%d",sum);

  
  printf("\n(3)\n");
  for (c=0; c<num; c++) {
    for (r=0; r<num; r++) {
      
      printf("%2d",numberBox[r][c]);
    }
    printf("\n");
  }
  
  
  for (r=0; r<num; r++) {
    free(numberBox[r]);
  }
  free(numberBox);

  return 0;
}
