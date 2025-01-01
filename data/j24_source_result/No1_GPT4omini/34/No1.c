#include <stdio.h>
#include <stdlib.h>
#define NUM 5

int main(){
  int i;
  int max=0,min=0;
  int sa=0;
  int *pt;

  pt=(int *)malloc(sizeof(int)*NUM);
  
  for(i=0;i<NUM;i++){
    scanf("%d",&pt[i]);
  }

  printf("配列の要素:");
  for(i=0;i<NUM;i++){
    printf(" %d ",pt[i]);
  }
  printf("\n");

  printf("逆順:");
  for(i=0;i<NUM;i++){
    printf(" %d ",pt[4-i]);
  }
  printf("\n");

  printf("最大値:");
  for(i=0;i<NUM;i++){
    if(max<pt[i])
      max=pt[i];
  }
  printf("%d",max);
  printf("\n");

  printf("最小値:");
  min=pt[0];
  for(i=0;i<NUM;i++){
     if(min>pt[i])
      min=pt[i];
  }
  printf("%d",min);
  printf("\n");

  printf("最大値と最小値の差:");
  printf("%d",max-min);
  printf("\n");
    
  
  free(pt);
  return 0;
}