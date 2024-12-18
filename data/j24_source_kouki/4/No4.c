#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int num = 0;
  int *pt;

  srand((unsigned)time(NULL));
  
  while(num <= 0) scanf("%d",&num);

  pt = (int *)malloc(sizeof(int)*num);

  for(int count = 0; count < num; count++) {
    pt[count] = rand()%100;
  }

  printf("(1)\n");
  for(int count = 0; count < num; count++) {
    printf("pt[%d] = %d\n", count, pt[count]);
  }

  printf("(2)\n");
  for(int count = 0; count < num; count++) {
    printf("pt[%d] = %d\n", num-1-count, pt[num-1-count]);
  }

  printf("(3)\n");
  for(int count = 0; count < num; count++) {
    if(pt[count]%2 == 0 && pt[count] != 0) printf("%d\n", pt[count]);
  }
  
  free(pt);
}
