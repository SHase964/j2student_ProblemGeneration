#include<stdio.h>
#include<stdlib.h>
int main(){
  int youso,i,sort;
  int *array;
  srand(1);
  scanf("%d",&youso);
  array = (int *)malloc(sizeof(int)*youso);
  for(i=0;i<youso;i++){
    array[i]=rand()%100;
  }
  printf("Original:");
  for(i=0;i<youso;i++){
    printf("%d ",array[i]);
  }
  printf("\nSorted  :");
  for(sort=0;sort<100;sort++){
    for(i=0;i<youso;i++){
      if(sort==array[i]){  
	printf("%d ",array[i]);
      }
    }
  }
  free(array);
  return 0;
}
