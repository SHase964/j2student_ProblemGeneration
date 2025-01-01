#include <stdio.h>
#include <stdlib.h>

int main(){

  int len,sum=0;
  int **array;
  printf("input:");
  scanf("%d",&len);
  array=(int**)malloc(sizeof(int*)*len);
  for(int i=0;i<len;i++) array[i]=(int*)malloc(sizeof(int)*len);


  for(int j=0;j<=len*len-1;j++){
    array[j/len][j%len]=j;
  }

  printf("gyouretu:");
  for(int j=0;j<=len*len-1;j++){
    if(j%len==0) printf("\n");
    for(int k=1;len*len-1>=k;k*=10) if(j<k&&!(j==0&&k==1)) printf(" ");
    printf("%d ",array[j/len][j%len]);
  }
  printf("\n");


  for(int j=0;j<len;j++){
    sum+=array[j][j];
  }

  printf("taikaku youso no sum:");
  printf("%d",sum);
  printf("\n");


  for(int i=0;i<len;i++) free(array[i]);
  free(array);

}
