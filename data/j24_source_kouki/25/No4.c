#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
  int *pt;
  int i;
  int NUM;
  int gyaku;
  int guusuu;
  scanf("%d",&NUM);
  srand((unsigned)time(NULL));

  pt= (int* )malloc(sizeof(int)*NUM);

  printf("(1)\n");
  for(i=0;i<NUM;i++){
    pt[i]=rand()%100;
    printf("pt[%d]=%d\n",i,pt[i]);
  }


  printf("(2)\n");
  for(i=0;i<NUM;i++){
    gyaku=pt[NUM-i-1];
    printf("gyaku=%d\n",gyaku);
  }

  printf("(3)\n");
  for(i=0;i<NUM;i++){
    if(pt[i]%2==0){
      guusuu=pt[i];
      printf("guusuu=%d\n",guusuu);
    }
  }
  
  free(pt);

  return 0;
}
