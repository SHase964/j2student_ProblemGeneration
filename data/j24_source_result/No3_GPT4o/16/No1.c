#include<stdio.h>
#include<stdlib.h>

int main(void){

  int num;
  int *i;
  int a;
  
  scanf("%d", &num);
  
  i=(int *)malloc(sizeof(int) * num);

  for(a=0; a<num; a++){
    scanf("%d", i);
  }

  printf("%d");

  for(a=0; a<num; a++){
    if(*i==*(i+a)){
      printf("%d ", *i);
    }
  }

  printf("\n");
  
  free(i);

  return 0;

}
