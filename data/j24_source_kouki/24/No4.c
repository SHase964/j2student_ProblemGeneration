#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
  int n,i;
  int *arr;
  srand((unsigned)time(NULL));
  
  printf("Hou many?\n");
  scanf("%d",&n);
  arr=(int *)malloc(sizeof(int)*n);

  printf("(1)\n");
  for(i=0;i<n;i++){
    arr[i]=rand();
    arr[i]%=100;
    printf("%2d  %d\n",i,arr[i]);
  }
  printf("\n");

  printf("(2)\n");
  for(i=n-1;i>=0;i--){
    printf("%2d %d\n",i,arr[i]);
  }

  printf("(3)\n");
  for(i=0;i<n;i++){
    if(i%2==0){
      printf("%2d %d\n",i,arr[i]);
    }
  }
  free(arr);
  return 0;
}
