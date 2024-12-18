#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int **numberBox;
  int i,count,count1,goukei;
  count1=0;
  goukei=0;
  i=0;
  srand((unsigned)time(NULL));
  printf("正方行列の大きさを決めてください:");
  scanf("%d",&count);
  numberBox = (int **)malloc(sizeof(int *) * count);
  printf("(1)\n");
  while(i<count){
  // i行目の列数
    numberBox[i] = (int *)malloc(sizeof(int) * count);
    while(count1<count){
      numberBox[i][count1]=rand()%10;
      printf("%d",numberBox[i][count1]);
      if(count1==i){
	goukei=goukei+numberBox[i][count1];
      }
      count1++;
    }
    count1=0;
    printf("\n");
    i++;
  }
  printf("(2)\n対角成分の合計:");
  printf("%d\n",goukei);
  
  i=0;
  while (i<count){
  free(numberBox[i]);
  i++;
  }
  free(numberBox);

  return 0;
}
