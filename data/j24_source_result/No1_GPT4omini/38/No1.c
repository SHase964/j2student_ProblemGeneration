#include <stdlib.h>
#include <stdio.h>


int main(void){

  int *pt;
  int a,b,c,i;
  int dummy;

  pt=(int *)malloc(sizeof(int)*5);

  for(i=0;i<5;i++){
    scanf("%d,%d",&pt[i],&dummy);
  }

  b=0;
  for(i<0;i<5;i++){
    a=pt[i];
    if(b<a){
      b=a;
    }
  }
  i=0;
  while(pt[i]==b){
    i++;
  }

  printf("最大値:%d(インデックス:%d)",b,pt[i]);


  c=b;
  for(i<0;i<5;i++){
    a=pt[i];
    if(a>c){
      c=a;
    }
  }
  i=0;
  while(pt[i]==c){
    i++;
  }

  printf("最小値:%d(インデックス:%d)",c,pt[i]);

  free(pt);
  return 0;
}
    
