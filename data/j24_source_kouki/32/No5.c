#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int i, j;
  int large;
  int *space;

  srand((unsigned)time(NULL));

  printf("\n(1)\n");
  printf("Input the number: ");
  scanf("%d", &large);

  space = (int *)malloc(sizeof(int)*(large*large+1));

  *space = 0;
  for(i=0;i<large;i++) {
    for(j=0;j<large;j++) {
      space[i][j] = rand()%100;
      printf("%d ", space[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  return 0;
}
