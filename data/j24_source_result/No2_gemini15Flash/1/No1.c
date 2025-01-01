#include<stdio.h>
#include<stdlib.h>

int main(void){
  
  int n;
  int *numberbox;

  printf("10以下の正の値での個数を入力してください\n");
  scanf("%d",&n);
   if(n>10){
    printf("error\n");
    return 0;
  }
    if(n<0){
    printf("error\n");
    return 0;
  }
  numberbox = (int *)malloc(sizeof(int) * n);

  int i,j,k,x,y;
  int num;
  int *newbox;
  
  for(i=0;i<n;i++){
    printf("%d個めの値\n",i+1);
    scanf("%d",&num);
    numberbox[i]=num;
  }

  y=0;
  for(j=0;j<n;j++){
    x = numberbox[j]%2;
    printf("num=%d",x);
    if(x==0){
      y++;
    }
  }
  

  
  free(numberbox);
  
  return 0;
}
