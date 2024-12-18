#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int i;
  int count=0;
  int *pt;
  srand((unsigned)time(NULL));
  printf("配列の数を入力してください:");
  scanf("%d",&i);
  pt = (int *)malloc(sizeof(int)*i+1);
  printf("(1)\n");
  while(count<i){
    pt[count]=rand()%100;
    printf("%d\n",pt[count]);
    count++;
  }
  pt[count]='\0';
  count--;
  printf("(2)\n");
  while(count>=0){
    printf("%d\n",pt[count]);
    count--;
  }
  count=0;
  printf("(3)\n");
  while(count<i){
    if(pt[count]%2==0){
      printf("%d\n",pt[count]);
    }
    count++;
  }
  free(pt);
  return 0;
}
