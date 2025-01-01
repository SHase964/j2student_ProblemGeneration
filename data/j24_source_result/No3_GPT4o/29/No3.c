#include <stdio.h>
#include <stdlib.h>

int main(){

  int *array,*rev,len;

  printf("input:");
  scanf("%d",&len);
  array=(int*)malloc(sizeof(int)*len);
  rev=(int*)malloc(sizeof(int)*len);

  printf("array:");
  for(int i=0;i<len;i++) scanf("%d",&array[i]);

  printf("rev:");
  for(int i=0;i<len;i++) rev[i]=array[len-1-i];

  for(int i=0;i<len;i++) printf("%d ",rev[i]);
  printf("\n");

  free(array);
  free(rev);

}
