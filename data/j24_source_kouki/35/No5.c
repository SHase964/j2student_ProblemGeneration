#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int i,j,k;
  int **array[][];

  printf("input number = ");
  scanf("%d",&k);
  
  array = (int **)malloc(sizeof(int *)*k);

  array[k] = (int *)malloc(sizeof(int *)*k);

  for(i=0; i<k; i+;){
    for(j=0; j<k; j+;){
      

  srand((unsigned)time(NULL));
