#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int **numberBox;
  int   i,j,len,wa;

  printf("len=");
  scanf("%d",&len);
  // 行数を決める
  numberBox = (int **)malloc(sizeof(int *) *len);
  
  for(i=0;i<len;i++){
    // i行目の列数
    numberBox[i] = (int *)malloc(sizeof(int) *len);
  }
  
  // nyuu力
  for(i=0;i<len;i++){
    for(j=0;j<len;j++){
      numberBox[i][j]=rand()%100;
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
      if(j != 0){   
	numberBox[i][0]=numberBox[i][0]+numberBox[i][j];
      }}}
  
  for(i=0;i<len;i++){
    printf("wa[%d]=%d ",i,numberBox[i][0]);
    wa=wa+numberBox[i][0];
  }
   printf("\nwa=%d ",wa);
   
  for(i=0;i<len;i++){
    free(numberBox[i]);
  }
  free(numberBox);
  
  return 0;
}
