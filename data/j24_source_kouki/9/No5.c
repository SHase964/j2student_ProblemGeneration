#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand((unsigned)time(NULL));
  int n;
  int **pt;
  printf("n = ");scanf("%d",&n);
  
  pt = (int **)malloc(sizeof(int *) * n);
  for(int i=0;i<n;i++){
    pt[i] = (int *)malloc(sizeof(int) * n);
  }
  printf("(1)\n");
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      pt[i][j] = rand()%10;
      printf("%d ",pt[i][j]);
    }
    printf("\n");
  }

  printf("\n(2)\n");
  int sum=0;
  for(int i=0;i<n;i++){
    sum += pt[i][i];
  }
  printf("sum = %d\n",sum);

  printf("\n(3)\n");
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int tmp;
      tmp = pt[i][j];
      pt[i][j] = pt[j][i];
      pt[j][i] = tmp;
    }
  }
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      printf("%d ",pt[i][j]);
    }
    printf("\n");
  }
  
  for(int i=0;i<n;i++){
    free(pt[i]);
  }
  free(pt);

  return 0;
}
