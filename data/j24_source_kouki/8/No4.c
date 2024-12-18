#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *array;
  int i,num;
  
  printf("num=");
  scanf("%d",&num);
  
  array = (int *)malloc(sizeof(int)*num);
  
  for (i=0; i<num; i++) {
    array[i] = rand()%100;
  }
  
  printf("(1)\n");
  for (i=0; i<num; i++) {
    printf("a[%d]=%d\n",i,array[i]);
  }
  printf("\n");
  
  printf("(2)\n");
  for (i=0; i<num; i++) {
    printf("a[%d]=%d\n",num-i-1,array[num-i-1]);
  }
  printf("\n");
  
  printf("(3)\n");
  for (i=0; i<num; i++) {
    if(array[i]%2==0){
      printf("a[%d]=%d\n",i,array[i]);
    }
  }
  printf("\n");
  
   free(array);
  return 0;
}
