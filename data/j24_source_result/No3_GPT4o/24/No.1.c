#include<stdio.h>
#include<stdlib.h>

int main(void){
  int n,i,ans;
  char *arr;
  printf("Hou many word?\n");
  scanf("%d",&n);
  arr=(char *)malloc(sizeof(char)*(n+1));

  printf("Input sentence\n");
  scanf("%f",&arr);
  for(i=0;i<n;i++){
    if((arr[i]<='a'&&arr[i]>='z')||(arr[i]<='A'&&arr[i]>='Z')){
      ans++;
    }
  }
  printf("&d\n",ans);
  free(arr);
  return 0;
}
