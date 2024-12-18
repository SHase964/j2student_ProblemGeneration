#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int **pt;
  int n;
  int i,j;
  int sum;
  int tmp;
  
  srand((unsigned)time(NULL));
  
  printf("n=");
  scanf("%d", &n);

  pt = (int **)malloc(sizeof(int *)*n);
  for (i=0; i<n; i++) {
    pt[i] = (int *)malloc(sizeof(int)*n);
  }
  
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      pt[i][j] = rand()%9;
    }
  }
  
  
  printf("(1)\n");
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      printf("%d ", pt[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  sum = 0;
  printf("(2)\n");
  for (i=0; i<n; i++) {
    sum += pt[i][i];
  }
  printf("sum = %d\n\n", sum);

  printf("(3)\n");
  for (i=0; i<n; i++) {
    for (j=i; j<n; j++) {
      tmp = pt[i][j];
      pt[i][j] = pt[j][i];
      pt[j][i] = tmp;
    }
  }
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      printf("%d ", pt[i][j]);
    }
    printf("\n");
  }
  printf("\n");



  for (i=0; i<n; i++) {
    free(pt[i]);
  }
  free(pt);
  
  return 0;
}
