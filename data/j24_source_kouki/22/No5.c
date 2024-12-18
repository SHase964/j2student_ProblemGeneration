#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int **ma;
  int *pt1;
  int *pt2;
  int i,j,k,n,sum;
  n = 0;

  srand((unsigned)time(NULL));
  
  printf("Input number = ");
  scanf("%d",&n);

  ma = (int **)malloc(sizeof(int)*n);
  
  for(i=0;i<n;i++){
    ma[i] = (int *)malloc(sizeof(int)*n);
  }

  printf("(1)\n");
  for(j=0;j<n;j++){
    for(k=0;k<n;k++){
      ma[j][k] = rand()%10;
      printf("%2d",ma[j][k]);
    }
    printf("\n");
  }

  for(j=0;j<n;j++){
    for(k=0;k<n;k++){
      if(j == k){
	sum +=ma[j][k];
      }
    }
  }

  printf("(2)\n");
  printf("sum = %d\n",sum);

  printf("(3)\n");
  for(j=0;j<n;j++){
    pt2 = &ma[k][j];
    ma[j][k] = *pt2;
  }
  for(k=0;k<n;k++){
      pt1 = &ma[j][k];
      ma[k][j] = *pt1;
      printf("%2d",ma[j][k]);
    }
    printf("\n");
    
  free(ma);

  return 0;

}
