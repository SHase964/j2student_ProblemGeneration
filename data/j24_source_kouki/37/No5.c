#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int func(int *a,int *b){
  int tmp;
  
  tmp=*a;
  *a=*b;
  *b=tmp;
}

int main(){
  int n,i,nn,ii,total;
  int **A;

  printf("n=");
  scanf("%d",&n);
  
  srand((unsigned)time(NULL));
  A=(int **)malloc(sizeof(int *)*n);

  nn=n;
  printf("(1)\n");
  for(i=0;i<n;i++){
    A[i]=(int *)malloc(sizeof(int)*n);
    for(ii=0;ii<nn;ii++){
      A[i][ii]=rand()%10;
      printf("%d ",A[i][ii]);
    }
    printf("\n");
  }
  printf("\n");

  total=0;
  printf("(2)");
  for(i=0;i<n;i++){
    total=total+A[i][i];
    printf("%d ",A[i][i]);
  }
  printf("=%d\n\n",total);

  printf("(3)\n");
  for(i=0;i<n;i++){
    for(ii=0;ii<nn;ii++){
      func(&A[i][ii],&A[ii][i]);
	}
  }
  
  for(i=0;i<n;i++){
    for(ii=0;ii<nn;ii++){
      printf("%d ",A[i][ii]);
    }
    printf("\n");
  }
  
  for(i=0;i<n;i++){
    free(A[i]);
  }
  free(A);

  return 0;
}
