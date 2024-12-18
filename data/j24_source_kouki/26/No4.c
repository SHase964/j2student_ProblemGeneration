#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_num(int *array,int num);
void reverse_array(int *array, int num);
void disp_guusuu(int *array, int num);

int main(void){
  int *array;
  int num;

  printf("(1)\n");
  printf("input the num : ");
  scanf("%d",&num);

  array = (int *)malloc(sizeof(int) * num);

  rand_num(array,num);

  printf("(2)\n");
  reverse_array(array,num);
  
  printf("(3)\n");
  disp_guusuu(array,num);

  free(array);
  
  return 0;
}

void rand_num(int *array,int num){
    srand((unsigned)time(NULL));
  
  for(int i = 0;i < num;i++){
    array[i] = rand() % 100;
    printf("array[%d] : %d\n",i,array[i]);
  }
}

void reverse_array(int *array, int num){
  for(int i = 0;i < num;i++){
    printf("reverse[%d] : %d\n",i,array[(num-1) - i]);
  }
}

void disp_guusuu(int *array, int num){
  printf("guusuu : \n");
  for(int i = 0;i < num;i++){
    if(array[i] % 2 == 0){
       printf("array[%d] : %d\n",i,array[i]);
    }
  }
}
