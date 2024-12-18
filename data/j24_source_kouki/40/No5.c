#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  int n,i,j,total=0;
  int **num;
  srand((unsigned)time(NULL));

  scanf("%d",&n);
  num=(int **)malloc(sizeof(int *)* n);
  for(i=0;i<n;i++){
    num[i]=(int *)malloc(sizeof(int)* n);
  }

  printf("(1)\n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      num[i][j]=rand()%10;
      printf("%d ",num[i][j]);
      if(i==j){
        total+=num[i][j];
      }
    }
    printf("\n");
  }

  printf("(2)\n");
  printf("%d\n",total);

  printf("(3)\n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%d ",num[j][i]);
    }
    printf("\n");
  }
  for(i=0;i<n;i++){
    free(num[i]);
  }
  free(num);
}
