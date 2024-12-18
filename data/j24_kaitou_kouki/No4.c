#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int *pt;
  int num;
  int i;

  srand((unsigned)time(NULL));
  
  printf("num=");
  scanf("%d", &num);

  pt = (int *)malloc(sizeof(int)*num);

  for (i=0; i<num; i++) {
    pt[i] = rand()%99;
  }

  
  printf("(1)\n");
  for (i=0; i<num; i++) {
    printf("%d\n", pt[i]);
  }
  printf("\n");

  printf("(2)\n");
  for (i=num-1; i>=0; i--) {
    printf("%d\n", pt[i]);
  }
  printf("\n");

  printf("(3)\n");
  for (i=0; i<num; i++) {
    if (pt[i]%2==0) {
      printf("%d\n", pt[i]);
    }
  }
  printf("\n");

  free(pt);
  
  return 0;
}
