#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){

  int i,x,j,max=0;
  int **y,*total;
  srand((unsigned)time(NULL));

  scanf("%d",&x);

  y=(int **)malloc(sizeof(int *)* x);

  for(i=0;i<x;i++){
    y[i]=(int *)malloc(sizeof(int)* x);
  }

  total=(int *)malloc(sizeof(int)* x);

  for(i=0;i<x;i++){
    total[i]=0;
  }

  for(i=0;i<x;i++){
    for(j=0;j<x;j++){
      y[i][j]=rand()%100;
      printf("%d",y[i][j]);
      total[i]+=y[i][j];
    }
  printf("\n");
  }

  for(i=0;i<x;i++){
    printf("%d",total[i]);
  }

  for(i=0;i<x;i++){
    if(max<total[i]){
      max=total[i];
    }
  }
  printf("%d",max);

  for(i=0;i<x;i++){
    free(y[i]);
  }
  free(y);
  free(total);
}
