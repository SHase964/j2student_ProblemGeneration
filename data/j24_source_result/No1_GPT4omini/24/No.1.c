#include<stdio.h>
#include<stdlib.h>
int main(void){
  int len,ans,i,tmp;
  int *arr,bab;
  printf("How many?\n");
  scanf("%d",&len);
  arr=(int *)malloc(sizeof(int)*len);
  for(i=0;i<len;i++){
    scanf("%d",&arr[i]);
  }
  for(i=0;i<len;i++){
    arr[i]=tmp;
    if(i>0){
      
  }
  if(len%2==0){
    ans=(double)(arr[(len/2)+1]+arr[len/2])/2;
  }
  else{
    ans=arr[len/2+1];
  }
  printf("average=%d\n",ans);
  free(arr);
  return 0;
}
