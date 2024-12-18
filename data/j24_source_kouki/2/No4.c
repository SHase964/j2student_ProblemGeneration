#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  srand((unsigned)time(NULL));
  
  int num;
  scanf("%d", &num);
  int *array;
  array = malloc(sizeof(int) * num);

  printf("\n(1)\n");
  for(int i = 0; i <num; i++) {
    array[i] = rand() % 100;
    printf("%d\n", array[i]);
  }

  printf("\n(2)\n");
  for(int i = 0; num - i > 0; i++) {
    printf("%d\n", array[num - i - 1]);
  }

  printf("\n(3)\n");
  for(int i = 0; i < num; i++) {
    if(array[i] % 2 == 0) {
      printf("%d\n", array[i]);
    }
  }
  
  free(array);
  return 0;
}
