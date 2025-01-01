#include<stdio.h>
#include<stdlib.h>

int main(){

  int num;
  int i;
  int max;
  int *pt;
  int *ptr;

  printf("何個整数を入力する?=");
  scanf("%d",&num);

  pt = (int *)malloc(sizeof(int) *(num+1));

  for(i=0; i<num; i++){
    scanf("%d",(pt+num-i));
  }

  for(i=0; i<num; i++){
    max=*(pt+i);
    if(max<*(pt+i)){
      max=*(pt+i);
    }
  }
  
  printf("max=%d\n",max);
  
  free(pt);
  return 0;
}
