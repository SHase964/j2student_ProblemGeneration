#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

  int **numbox;
  int i;
  int j;
  int num = 0;
  int taikaku;
  taikaku = 0;
  srand((unsigned)time(NULL));

  while(num<1){
    printf("(1)1以上の整数を入力\n n の値：");
    scanf("%d", &num);
  }

  numbox = (int **)malloc(sizeof(int *) *num);
  for(i=0; i<num; i++){
    numbox[i] = (int*)malloc(sizeof(int) *num);
  }

  for(i=0; i<num; i++){
    for(j=0; j<num; j++){
      numbox[i][j] = rand()%10;
      printf("%d ", numbox[i][j]);
      if(i==j){
	taikaku = taikaku + numbox[i][j];
      }
     }
    printf("\n");
  }

  printf("\n(2)対角成分の和：%d\n", taikaku);

  printf("\n(3)転置行列\n");
  for(i=0; i<num; i++){
    for(j=0; j<num; j++){
      printf("%d ", numbox[j][i]);
    }
    printf("\n");
  }

  free(numbox);
  return 0;
}
  
