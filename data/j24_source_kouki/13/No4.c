#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int *array;
  int i,num;
  char no;
  srand((unsigned)time(NULL));
  printf("num=");
  scanf("%d",&num);
  scanf("%c",&no);
  array=(int *)malloc(sizeof(int)*(num+1));
  printf("(1)\n");
  for(i=0;i<num;i++){
    array[i]=rand()%100;
    printf("%2d\n",array[i]);
  }
  printf("\n(2)\n");
  for(i=num-1;i>=0;i--){
    printf("%2d\n",array[i]);
  }
  printf("\n(3)\n");
  for(i=0;i<num;i++){
    if(array[i]%2==0){
      printf("%2d\n",array[i]);
    }
  }
  free(array);
  return 0;
}
