#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int *array;
  int *up_array;
  int num = 0;
  int mid_num = 0;
  int num_index = 0;

  srand((unsigned)time(NULL));

  scanf("%d",&num);

  array = (int *)malloc(sizeof(int) * num);
  up_array = (int *)malloc(sizeof(int) * num);
  
  for(int i = 0;i < num;i++){
    array[i] = rand() % 10;
    printf("array[%d] : %d\n",i,array[i]);
  }


  for(int k = 0;k < num;k++){
    for(int i = 0;i < num;i++){
      if(mid_num < array[i]){
	mid_num = array[i];
	num_index = i;
      }
    }
    up_array[k] = mid_num;
    printf("up_array[%d] : %d\n",k,up_array[k]);
    mid_num = 0;
    array[num_index] = -1;
  }

  printf("%d\n",mid_num);

  free(array);
  
  return 0;
}
    
  
