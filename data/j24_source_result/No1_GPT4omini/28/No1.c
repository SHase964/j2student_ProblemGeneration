#include<stdio.h>
#include<stdlib.h>

int main(){
  int *pt;
  int num;
  int i;
  int sum=0;
  double ave;


  printf("何個配列を作る?\n");
  scanf("%d",&num);

  pt=(int *)malloc(sizeof(int)*(num+1));

  for(i=0; i<num; i++){
    printf("配列の要素を入力してください:");
    scanf("%d",pt);
    sum +=*pt;
  }

  ave=(double)sum/num;

  printf("平均値=%f\n",ave);
  free(pt);
  return 0;
}
  
