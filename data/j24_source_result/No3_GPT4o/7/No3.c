#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int *array;
  int *array2;
  int i,j;
  int num,num2,small;
  
  printf("何個の整数を生成しますか？ー＞");
  scanf("%d",&num);

  array = (int *)malloc(sizeof(int) * num);
  array2 = (int *)malloc(sizeof(int) * num);
    
  srand((unsigned)time(NULL));

  for(i=0;i<num;i++){
    array[i] = rand()%10;
    printf("%d ",array[i]);
  }

  printf("\n");
  
  for(i=0;i<num;i++){
    small = 10;
    num2 = 0;
    for(j=0;j<num;j++){
      if(array[j]<small){
	small = array[j];
	num2 = j;
      }
    }
    array2[i] = small;
    array[num2] = 10;
  }

  for(i=0;i<num;i++){
    printf("%d ",array2[i]);
  }
  
  free(array);
  free(array2);

  return 0;
}
