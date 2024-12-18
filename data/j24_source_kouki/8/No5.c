#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int **numberBox;
  int   i,j,len,wa;

  printf("len=");
  scanf("%d",&len);
  // 行数を決める
  numberBox = (int **)malloc(sizeof(int *) *(len+1));
  
  for(i=0;i<len;i++){
    // i行目の列数
    numberBox[i] = (int *)malloc(sizeof(int) *(len+1));
  }
  
  // nyuu力
  for(i=0;i<len;i++){
    for(j=0;j<len;j++){
      numberBox[i][j]=rand()%10;
    }
  }
  
  printf("(1)\n");     //(1)
  for(i=0;i<len;i++){
    for(j=0;j<len;j++){
      printf("%d ",numberBox[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  
  printf("(2)\n");        //(2)
  wa=0;
  for(i=0;i<len;i++){
    for(j=0;j<len;j++){
      if(i==j){
	wa=wa+numberBox[i][j];
      }
    }
  }
  printf("wa=%d\n\n",wa);
  
  printf("(3)\n");     //(3)
  int **a;
   a = (int **)malloc(sizeof(int *) *(len+1));
    for(i=0;i<len;i++){
    a[i] = (int *)malloc(sizeof(int) *(len+1));
  }
  for(i=0;i<len;i++){
    for(j=0;j<len;j++){
      a[i][j]= numberBox[i][j];
    }
  }
  
  for(i=0;i<len;i++){
    for(j=0;j<len;j++){
      numberBox[i][j]=a[j][i];
    }
  }
   for(i=0;i<len;i++){
    for(j=0;j<len;j++){
      printf("%d ",numberBox[i][j]);
    }
    printf("\n");
  }

   
  for(i=0;i<len;i++){
    free(numberBox[i]);
    free(a[i]);
  }
  free(numberBox);
  free(a);
  
  return 0;
}
