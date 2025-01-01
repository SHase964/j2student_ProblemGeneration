#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand((unsigned)time(NULL));
  int n;
  int m=3;
  int **pt;
  printf("n = ");scanf("%d",&n);

  pt = (int **)malloc(sizeof(int *) * n);
  for(int i=0;i<n;i++){
    pt[i] = (int *)malloc(sizeof(int) * m);
  }

  for(int i=0;i<n;i++){
    int sum=0;
    for(int j=0;j<m;j++){
      pt[i][j] = rand()%100;
      printf("%d ",pt[i][j]);
      sum+=pt[i][j];
    }
    printf("%d sum : %d\n",i+1,sum);
  }
  
  for(int i=0;i<n;i++){
    free(pt[i]);
  }
  free(pt);
  
  
  
  
  return 0;
}
