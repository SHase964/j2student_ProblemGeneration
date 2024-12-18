#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand((unsigned)time(NULL));
  
  int **numbox;
  int i,j;
  int n;
  int sum = 0;

  printf("n=");
  scanf("%d", &n);

  numbox = (int **)malloc(sizeof(int *) * n);

  printf("(1)");
  for (i=0; i<n; i++) {
    numbox[i] = (int *)malloc(sizeof(int) * n);
    printf("\n");
    for (j=0; j<n; j++) {
      numbox[i][j] = rand()%10;
      printf("%d ", numbox[i][j]);
      if (i == j) {
	sum = sum+numbox[i][j];
      }
    }
  }
  printf("\n");
  
  printf("\n(2)\n");
  printf("sum=%d\n", sum);

  printf("\n(3)");
  for (j=0; j<n; j++) {
    printf("\n");
    for (i=0; i<n; i++) {
      printf("%d ", numbox[i][j]);
    }
  }
  printf("\n");
  
  for(i=0; i<n; i++) {
    free(numbox[i]);
  }
  free(numbox);
  return 0;

}
