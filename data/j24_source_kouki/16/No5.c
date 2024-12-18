#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
  int n;
  int i;
  int r;
  int a,b;
  int **array;
  int *num;
  
  srand((unsigned)time(NULL));
  
  n = rand()%8+1;

  //行
  array = (int **)malloc(sizeof(int *) * n);

  //列
  for(i=0; i<n; i++){
    array[i] = (int *)malloc(sizeof(int) * n);

    for(a=0; a<=n; a++){
      array[a][b] = num[]
	}
  }


  
