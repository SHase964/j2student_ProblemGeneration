#include <stdio.h>
#include <stdlib.h>

int main(void){

  int a;
  printf("文字列の数を入力\n");
  scanf("%d",&a);
  int **array;
  *array = (int **)malloc(sizeof(int*)*a);
  
  printf("ローマ字で文字を入力\n最後にendを入れること\n");
  for(int i=0; i<a; i++){
    array[i] = (int *)malloc(sizeof(int)*30);
    scanf("%d",&array[i]);
    
  }

  for(int i=0; i<a; i++){
    for(int j=0; j>0; i--)
  }
}
