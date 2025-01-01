#include <stdio.h>
#include <stdlib.h>

int main(){

  int *pt;
  int *junban;
  int num;
  int i,j;

  printf("配列の個数を指定\n");
  scanf("%d",&num);

  pt = (int *)malloc(sizeof(int)*num);
  junban = (int *)malloc(sizeof(int)*num);
  

  printf("配列の要素を入力\n");
  for(i=0;i<num;i++){
    scanf("%d",&pt[i]);
  }

  int smallnum=999;
  int smallzone;
  for(j=0;j<num;j++){
    for(i=0;i<num;i++){
      if(pt[i]<smallnum){
	smallnum = pt[i];
	smallzone = i;
      }
    }

    pt[smallzone] = 999;
    
    for(i=0;i<num;i++){
      if(pt[i]==smallnum){
	junban[j] = smallnum;
      }
    }
    
  }

  for(i=0;i<num;i++){
    printf("%d",junban[i]);
  }

  //時間が足りない

  free(pt);
  free(junban);
  
  return 0;
}
    
  
