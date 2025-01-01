#include <stdio.h>
#include <stdlib.h>

int main(void){
  int n;
  int a,b;
  int *number;
  int *jyun;

  printf("Enter the number\n");
  scanf("%d",&n);

  number = (int *)malloc(sizeof(int)*(n));
  jyun = (int *)malloc(sizeof(int)*(n));

  printf("Sorted array:\n");

  for(a=0;a<n-1;a++){
    scanf("%d ",&number[a]);
  }

  b = 0;
  
  for(a=0;a<n-1;a++){
    if(number[a]<number[a+1]){
      jyun[b] = number[a];
    }else{
      jyun[b] = number[a+1];
    }
    b++;
  }

  printf("Even numbers:\n");

  for(b=0;b<n-1;b++){
    printf("%d ",jyun[b]);
  }
  
  free(number);
  
  return 0;
}
