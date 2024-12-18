#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int *array;
  int i;
  int n;
  char dummy;

  srand((unsigned)time(NULL));
  printf("num=");
  scanf("%d",&n);
  scanf("%c",&dummy);
  array=(int *)malloc(sizeof(int)*n);
  printf("(1)\n");
  for(i=0;i<n;i++){
    array[i]=rand()%100;
    printf("%d\n",array[i]);
  }
  printf("\n(2)\n");
  for(i=n-1;i>-1;i--){
    printf("%d\n",array[i]);
  }
  printf("\n(3)\n");
  for(i=0;i<n;i++){
    if(array[i]%2==0){
      printf("%d\n",array[i]);
    }
  }
  free(array);
  return 0;
}
