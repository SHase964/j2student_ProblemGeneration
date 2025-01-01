#include<stdio.h>
#include<stdlib.h>

int main(void){
  int *pt;
  int i,n;
  int min[n];
  
  printf("格納したい要素数を入力する。");
  scanf("%d",&n);

  pt = (int *)malloc(sizeof(int)*n);
  
  for(i=0;i<n;i++){
    scanf("%d",pt[i]);
    if(i==0){
      min[0] = pt[i];
    }
    if(min[0]>pt[i]){
      min[i] = min[i-1];
      min[0] = pt[i];
    }
    printf("%d\n",pt[i]);
    
  }
  
  free(pt);

  return 0;
}
