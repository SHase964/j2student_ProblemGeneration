#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  srand((unsigned)time(NULL));
  int n,m;
  int **pt;
  int sum=0;
  printf("m = ");scanf("%d",&m);
  printf("n = ");scanf("%d",&n);

  pt = (int **)malloc(sizeof(int *)*m);
  for(int i=0;i<m;i++){
    pt[i] = (int *)malloc(sizeof(int)*n);
  }

  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      pt[i][j]=rand()%100;
      sum+=pt[i][j];
    }
  }

  for(int i=0;i<m;i++){
    printf("[ ");
    for(int j=0;j<n;j++){
      printf("%d ",pt[i][j]);
    }
    printf("] ");
  }
  printf("\n");
  for(int i=0;i<m;i++){
    printf("[ ");
    for(int j=n-1;j>=0;j--){
      printf("%d ",pt[i][j]);
    }
    printf("] ");
  }
  printf("\n");

  printf("sum = %d\n",sum);
  for(int i=0;i<m;i++){
    free(pt[i]);
  }
  free(pt);
  


  
  return 0;
}
