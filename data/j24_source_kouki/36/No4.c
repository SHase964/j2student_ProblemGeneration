#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand((unsigned)time(NULL));
  
  int i;
  int num;
  int *array;
  
  printf("num=");
  scanf("%d", &num);
  printf("\n");
  
  array = (int*)malloc(sizeof(int) * num);

  printf("(1)\n");
  for (i=0; i<num; i++) {
    array[i] = rand()%100;

    printf("%d\n", array[i]);
  }

  printf("\n(2)\n");
  for (i=num; i>0; i--) {
    printf("%d\n", array[i-1]);
  }

  printf("\n(3)\n");
  for (i=0; i<num; i++) {
    if (array[i]%2 == 0 || array[i] == 0) {
      printf("%d\n", array[i]);
    }
  }
  
  free(array);
  return 0;
}
