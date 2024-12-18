#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

  int a;
  int *num;
  int *another;

  printf("num = ");
  scanf("%d",&a);
  num     = (int *)malloc(sizeof(int)*a);
  another = (int *)malloc(sizeof(int)*a);

  srand((unsigned)time(NULL));

  printf("(1)\n");
  for(int i=0; i<a; i++){
    num[i] = rand()%100;
    printf("%d\n",num[i]);
  }
  printf("(2)\n");
  for(int i=0; i<a; i++){
    another[i] = num[a-i-1];
    printf("%d\n",another[i]);
  }
  printf("(3)\n");
  for(int i=0; i<a; i++){
    if(num[i]%2==0){
      printf("%d\n",num[i]);
    }
  }
  free(num);   free(another);
  return 0;
}
