#include <stdio.h>
#include <stdlib.h>

int main(void){
  int i,j;
  int **array;
  int num,num2;
  int result,result2;
  
  printf("何行何列の行列を生成しますか？ー＞");
  scanf("%d",&num);
  while(num<1){
    printf("１以上の値で入力してください。\n何行何列の行列を生成しますか？ー＞");
    scanf("%d",&num);
  }

  array = (int **)malloc(sizeof(int *) * num);
  for(i=0;i<num;i++){
    array[i] = (int*)malloc(sizeof(int) * num);
  }

  num2 = 1;
  for(i=0;i<num;i++){
    printf("| ");
    for(j=0;j<num;j++){
      array[i][j] = num2;
      printf("%2d ",array[i][j]);
      num2 = num2 + 1;
    }
    printf("|\n");
  }

  result2 = 0;
  printf("列の合計： ")
  for(i=0;i<num;i++){
    result=0;
    for(j=0;j<num;j++){
      result = result + array[i][j];
      printf("%d",result) 
    }
  }

  for(j=0;j<num;j++){
    for(i=0;i<num;i++){
      result2 = result2 + array[i][j]

    
  for(i=0;i<num;i++){
    free(array[i]);
  }
  free(array);

  return 0;
}
