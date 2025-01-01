#include<stdio.h>
#include<stdlib.h>
#define NUM 5

int main(){
  int *array;
  int i;

  array=(int*)malloc(NUM*sizeof(int));

  printf("(1)");
  for(i=0;i<NUM;i++){
    array[i]=i;
    printf("%d",array[i]);
  }
  printf("\n");

  int bai(&array);


  free(array);
  return 0;
}

int bai(num){
  int i;

  num=(int *)malloc(NUM*sizeof(int));

  for(i=0;i<NUM;i++){
    num[i]=

  return num;
}
