#include<stdio.h>
#include<stdlib.h>

int main(void) {

  int **pt;
  int n;

  do{
    printf("n=");
    scanf("%d",&n);
  }
  while(n <= 0);

  printf("\n");

  pt = (int **)malloc(sizeof(int*) * n);
  for(int i=0; i<n; i++){
    pt[i] = (int *)malloc(sizeof(int) * n);
  }


  int k=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
    pt[i][j] = k;
    k++;
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      printf("%2d ",pt[i][j]);
    }
    printf("\n");
  }

  int cul =0;
  printf("各行の合計:\n");
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
    cul += pt[i][j];
    }
    printf("%d\n",cul);
    cul=0;
  }

  free(pt);


  return 0;
}
