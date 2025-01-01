#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  int **numberBox;
  int i,n;

  scanf("%d",&n);

  while(i=0,i<=n,i++){
   numberBox=(int **)malloc(sizeof(int*)*i);
   numberBox[i]=(int *)malloc(sizeof(int)*n);
   printf("numberBox[%d][%d]=%d\n",0,n);
}

  return 0;
}
