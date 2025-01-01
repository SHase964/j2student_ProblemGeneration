#include<stdio.h>
#include<stdlib.h>

int main(void){
  
  int n;
  int *numberbox;

  printf("size=")
  scanf("%d",&n);
  numberbox = (int *)malloc(sizeof(int) * n);

  int i,j;
  int num;
  
  for(i=0;i<n;i++){
    scanf("%d",&num);
    numberbox[i]=num;
  }

  for(j=0;j<n;j++){
    printf("num=%d",numberbox[j]);
  }
  
  if(numberbox){
  }
  
  free(numberbox);
  
  return 0;
}
