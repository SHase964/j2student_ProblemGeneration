#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {

  int *pt;
  char dummy;

  srand((unsigned)time(NULL));
  int len;
  do
  {
    printf("配列の長さ: ");
    scanf("%d",&len);
    scanf("%c",&dummy);
  }
  while(len<=0);

  pt = (int*)malloc(sizeof(int) * len);


  printf("配列の要素: ");
  for(int i=0; i<len; i++){
    scanf("%d",&pt[i]);
    scanf("%c",&dummy);
  }

  printf("配列: ");
  for(int i=0; i<len; i++){
    printf("%d ",pt[i]);
  }
  printf("\n");

  int max;
  max = pt[0];
  for(int i=0; i<len; i++){
    if(max < pt[i])max = pt[i];
  }

  int min;
  min = pt[0];
  for(int i=0; i<len; i++){
    if(min > pt[i])min = pt[i];
  }

  printf("\n最大値は%d、最小値は%d、差は%dです。\n",max,min,max-min);


  free(pt);
  return 0;
}
