#include <stdio.h>
#include <stdlib.h>

#define NUM 5

void maxmin(int *space);
  
int main(void) {
  int array[NUM] = {1,20,300,40,5};
  
  maxmin(array);

  return 0;
}

void maxmin(int *space) {
  int i;
  int max;
  int min;
  
  space = (int *)malloc(sizeof(int)*(NUM+1));

  *space = 0;
  for(i=0;i<NUM;i++) {
    if(max < space[i]) {
      max = space[i];
    }
    if(min > space[i]) {
      min = space[i];
    }
  }
  printf("MAX:%d ", max);
  printf("MIN:%d ", min);
  printf("\n");

  free(space);
}
