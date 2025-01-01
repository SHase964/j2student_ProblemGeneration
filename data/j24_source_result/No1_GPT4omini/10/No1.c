#include <stdio.h>
#include <stdlib.h>

int main(){
  int num;
  int i;
  int *pt;

  pt=(int*)malloc(sizeof(int)*5);

  for(i=0;i<5;i++){
  printf("要素入力＝");
  scanf("%d",&num);
  pt[i]=num;
  }

  int cen;
  int j;
  int c;

  for(j=0;j<3;j++){
    cen=0;
    for(i=0;i<5;i++){
      if(cen<pt[i]){
	cen=pt[i];
      }
    }
    for(i=0;i<5;i++){
      if(cen==pt[i]){
      pt[i]=0;
    }
    }
    
  }
  
  printf("中央値は%dです\n",cen);
}
  
  
