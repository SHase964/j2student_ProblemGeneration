#include<stdio.h>
#include<stdlib.h>
int main(){
  int NUM,i;
  int *pt;
  printf("NUM=");
  scanf("%d",&NUM);
  printf("(1)\n");
  pt = (int *)malloc(sizeof(int)*NUM);
  for(i=0;i<NUM;i++){
    pt[i]=rand()%99;
    printf("%d\n",pt[i]);
    }
   printf("(2)逆順に出力\n");
   for(i=NUM-1;i>=0;i--){
     printf("%d\n",pt[i]);
    }
   printf("(3)偶数のみ出力\n");
   for(i=0;i<NUM;i++){
     if(pt[i]%2==0){
     printf("%d\n",pt[i]);
     }
    }
  return 0;
}

