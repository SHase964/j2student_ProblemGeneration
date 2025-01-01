#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  int i;
  int *pt;
  int mozi;
  int gyaku;
  char str[];
  scanf("%d",&mozi);

  pt=(int* )malloc(sizeof(int)*mozi);



  for(i=mozi-1;i>=0;i--){
    char str []=mozi;
    printf("gyaku=%c\n",mozi);
  }
  return 0;
}
