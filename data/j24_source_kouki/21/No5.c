#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  int **pt;
  int n;
  int i,j;

  printf("n = ");
  scanf("%d",&n);

  pt = (int **)malloc(sizeof(int *)*n);

  for(i=0;i<n;i++){
    pt[i] = (int *)malloc(sizeof(int)*n);
  }

  srand((unsigned)time(NULL));

  printf("\n(1)\n");
  
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      pt[i][j] = rand()%10;
    }
  }

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf(" %d",pt[i][j]);
    }
    printf("\n");
  }

  
  printf("\n(2)\n");

  int sum=0;

  for(i=0;i<n;i++){

    sum += pt[i][i];

  }

  printf("sum = %d\n",sum);

  
  printf("\n(3)\n");

  int keep;

  for(i=0;i<n;i++){

    for(j=0;j<n;j++){

      if(i<j){
	keep = pt[i][j];
	pt[i][j] = pt[j][i];
	pt[j][i] = keep;
      }

    }

  }

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf(" %d",pt[i][j]);
    }
    printf("\n");
  }

  

  for(i=0;i<n;i++){
    free(pt[i]);
  }
  
  free(pt);

  return 0;
}
