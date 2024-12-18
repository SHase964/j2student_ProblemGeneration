#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
  int n,i,j,sum;
  int **arr;
  int **tmp;
  srand((unsigned)time(NULL));

  printf("How many?\n");
  scanf("%d",&n);

  printf("(1)\n");
  arr=(int **)malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    arr[i]=(int *)malloc(sizeof(int)*n);
    for(j=0;j<n;j++){
      arr[i][j]=rand();
      arr[i][j]%=10;
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }

  printf("(2)\n");
  for(i=0;i<n;i++){
    sum+=arr[i][i];
  }
  printf("%d\n",sum);

  printf("(3)\n");
  tmp=(int **)malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    tmp[i]=(int *)malloc(sizeof(int)*n);
    for(j=i;j<n;j++){
      tmp[i][j]=arr[i][j];
      arr[i][j]=arr[j][i];
      arr[j][i]=tmp[i][j];
    }
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
  free(arr);
  return 0;
}
