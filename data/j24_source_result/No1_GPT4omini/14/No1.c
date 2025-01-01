#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int input(void){
  int num;
  printf("いくつの数字を表示させますか:");
  scanf("%d",&num);
  return num;
}

void max_min(int *min,int *max,int *array){
  int i=0;
  *max=0;
  *min=100;
  while(array[i]!='\0'){
    if(array[i]>*max){
      *max=array[i];
    }
    if(array[i]<*min){
      *min=array[i];
    }
    i++;
  }
  i=0;
}

int main(void){
  int i,min,max;
  int count=0;
  int *pt;
  srand((unsigned)time(NULL));
  i=input();
  pt=(int *)malloc(sizeof(int)*i+1);
  while(count<i){
    pt[count]=rand()%100;
    printf("%d\n",pt[count]);
    count++;
  }
  pt[count]='\0';
  max_min(&min,&max,pt);
  printf("最大値:%d\n",max);
  printf("最小値:%d\n",min);
  return 0;
}
