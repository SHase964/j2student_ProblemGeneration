#include<stdio.h>
#include<stdlib.h>

int main(){
  int i,j;
  int size=0,kazu=0;
  int *pt;

  printf("サイズ:");
  scanf("%d",&size);

  pt=(int *)malloc(sizeof(int)*size);

  printf("リスト:");
  for(i=0;i<size;i++){
    pt[i]=i+2;
    printf("%d ",pt[i]);
  }
  printf("\n");

  for(i=0;i<size;i++){
    for(j=0;j<i+1;j++){
      if((pt[i]%i+2)==0){
	kazu=kazu+1;
	break;
      }
    }
  }
  printf("素数の数:%d\n",kazu);
  free(pt);
}
