#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int i,a,b;
  int* array;

  printf("please number");
  scanf("%d",&a);

  srand((unsigned)time(NULL));
  array=(int *)malloc(sizeof(int)*a);

  printf("(1)");
  for(i=0;i<a;i++){
    array[i]=rand()%100;
    printf("%d ",array[i]);
  }
  printf("\n");

  i=i-1;
  printf("(2)");
  while(i>=0){
    printf("%d ",array[i]);
    i=i-1;
  }
  printf("\n");

  printf("(3)");
  for(i=0;i<a;i++){
    if(array[i]%2==0){
      printf("%d ",array[i]);
    }
  }
  printf("\n");
  
  free(array);
  return 0;
}
