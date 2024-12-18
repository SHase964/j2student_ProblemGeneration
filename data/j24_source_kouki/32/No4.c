#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int i;
  int large;
  int *space;
  int oddcheck;
  
  srand((unsigned)time(NULL));

  printf("\n(1)\n");
  printf("Input the number: ");
  scanf("%d", &large);

  space = (int *)malloc(sizeof(int)*(large+1));

  *space = 0;
  for(i=0;i<large;i++) {
    space[i] = rand()%100;
    printf("%d ", space[i]);
  }
  printf("\n");

  printf("\n(2)\n");
  
  for(i=0;i<large;i++) {
    printf("%d ", space[large-i-1]);
  }
  printf("\n");

  printf("\n(3)\n");

  for(i=0;i<large;i++) {
    oddcheck = space[i] % 2;
    if(oddcheck == 0) {
      printf("%d ", space[i]);
    }
  }
  printf("\n");
  
  free(space);
  return 0;
}
