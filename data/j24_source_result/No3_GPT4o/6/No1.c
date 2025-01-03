#include <stdio.h>
#include <stdlib.h>

int main(void){

  int **numbox;
  int i;
  int j;
  int n;
  int num;
  num = 0;
  n = 1;
  
   while(num<1){
    printf("(1)1以上の整数を入力\n n = ");
    scanf("%d", &num);
  }

  numbox = (int **)malloc(sizeof(int *) *num);
  for(i=0; i<num; i++){
    numbox[i] = (int*)malloc(sizeof(int) *num);
  }

  printf("Original Matrix:\n");
  for(i=0; i<num; i++){
    for(j=0; j<num; j++){
      numbox[i][j] = n;
      printf("%d ", numbox[i][j]);
      n++;
      if(i==j){
        numbox[i][j] *= 2;
      }
    }
    printf("\n");
  }
  
  printf("Modified Matrix:\n");
  for(i=0; i<num; i++){
    for(j=0; j<num; j++){
      printf("%d ", numbox[i][j]);
    }
    printf("\n");
  }
  
  free(numbox);
  return 0;
}
