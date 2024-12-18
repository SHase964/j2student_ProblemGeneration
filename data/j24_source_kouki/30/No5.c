#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int my_rand(int min,int max)
{
  return rand()%(max-min+1)+min;
}//my_rand(1,5)

void disp(int **gyo,int n){
  int i,j;
  for (i=0;i<n;i++){
    for (j=0;j<n;j++){
      printf("%d ",gyo[i][j]);
    }
    printf("\n");
  }
}

int taikakuwa(int **gyo,int n){
  int res=0;
  for (int i=0;i<n;i++){
    res=res+gyo[i][i];
  }
  return res;
}

void tenchi(int **gyo,int i,int j){
  int tmp;
  tmp=gyo[i][j];
  gyo[i][j]=gyo[j][i];
  gyo[j][i]=tmp;
}


int main(void)
{
  int n,i,j;
  int **gyo;
  //int *retsu;
  srand((unsigned)time(NULL));
  printf("n=");
  scanf("%d",&n);
  gyo=(int **)malloc(sizeof(int *)*n);
  for(i=0;i<n;i++){
    gyo[i]=(int *)malloc(sizeof(int)*n);
    for (j=0;j<n;j++){
      gyo[i][j]=my_rand(0,9);
    }
  }
  printf("(1)\n");
  disp(gyo,n);
  printf("\n(2)\n");
  printf("num=%d\n\n",taikakuwa(gyo,n));
  printf("(3)\n");
  for (i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(j>i){
	tenchi(gyo,i,j);
      }
    }
  }
  disp(gyo,n);
  for (i=0;i<n;i++){
    free(gyo[i]);
  }
  free(gyo);
  return 0;//free check!!!
}
