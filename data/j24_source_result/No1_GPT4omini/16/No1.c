#include<stdio.h>
#include<stdlib.h>

int main(void){
  int *num;
  int k;
  int a;

  printf("数字を入力する回数");
  scanf("%d", &k);
  
  num = (int *)malloc(sizeof(int) * k);

  for(a=1; a<=k; a++){
    scanf("%d", i+a);
  }

  int max=0;
  for(a=1; a<=k; a++){
    if(num[a] > max){
      max = num[a];
    }
  }
  printf("Max : %d\n", max)

  
  int min=100000000;
  for(a=1; a<=k; a++){
    if(num[a] < min){
      min = num[a];
    }
  }
  printf("Min : %d\n", min);

  for(a=1; a<=k; )

  return 0;

  free(i);
}
