#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int input(void){
  int num;
  scanf("%d",&num);
  return num;
}

void q2(int *array){
  int max=0;
  int i=0;
  while(array[i]!='\0'){
    if(array[i]>max){
      max=array[i];
    }
    i++;
  }
  printf("max:%d\n",max);
}

void q3(int *array){
  int ittan=0;
  int i=0;
  int j=0;
  int min = 10;
  int memo;
  while(array[i]!='\0'){
    if(array[i]<min){
      min=array[i];
      memo=i;
    }
    i++;
  }
  printf("min=%d\n",min);
  array[memo]=array[0];
  array[0]=min;
  i=1;
  while(array[i]!='\0'){
    j=i;
    min=10;
    while(array[j]!='\0'){
      if(array[j]<min){
	min=array[j];
	memo=j;
      }
      j++;
    }
    printf("%d\n",min);
    array[memo]=array[i];
    array[i]=min;
    i++;
    printf("%d\n",array[i]);
  }
}

int main(void){
  int i;
  int count=0;
  int *pt;
  srand((unsigned)time(NULL));
  i=input();
  pt = (int *)malloc(sizeof(int)*i+1);
  while(count<i){
    pt[count]=rand()%10;
    printf("%d\n",pt[count]);
    count++;
  }
  pt[count]='\0';
  q2(pt);
  q3(pt);
  while(count<i){
    printf("%d\n",pt[count]);
    count++;
  }
  return 0;
}
