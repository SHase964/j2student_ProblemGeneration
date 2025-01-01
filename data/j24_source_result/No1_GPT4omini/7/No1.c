#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int check(int *pt,int num){
  int i,small,big;
  small = 11;
  big = 0;
  for(i=0;i<num;i++){
    if(small>pt[i]){
      small = pt[i];
    }
  }

  for(i=0;i<num;i++){
    if(big<pt[i]){
      big = pt[i];
    }
  }  
    printf("最大値：%d\n最小値：%d\n",big,small);
}
  
  

int main(void){
  int *pt;
  int i,num,big,small;

  srand((unsigned)time(NULL));

  printf("整数を何個生成しますか？ー＞");
  scanf("%d",&num);

  pt = (int *)malloc(sizeof(int)*num);

  for(i=0;i<num;i++){
    pt[i] = rand()%10;
  }

  for(i=0;i<num;i++){
    printf("%d",pt[i]);
  }
  printf("\n");

  check(pt,num);
  
  free(pt);
  return 0;
}
