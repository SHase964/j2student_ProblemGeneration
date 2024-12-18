#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int my_rand(int min,int max)
{
  return rand()%(max-min+1)+min;
}//my_rand(1,5)

int main(void)
{
  int num,i;
  int *list;
  srand((unsigned)time(NULL));
  printf("num=");
  scanf("%d",&num);
  list=(int *)malloc(sizeof(int)*num);
  for(i=0;i<num;i++){
    list[i]=my_rand(0,99);
  }
  printf("(1)\n");
  for (i=0;i<num;i++){
    printf("%d\n",list[i]);
  }
  printf("\n(2)\n");
  for (i=num;0<i;i--){
    printf("%d\n",list[i-1]);
  }
  printf("\n(3)\n");
  for (i=0;i<num;i++){
    if(!(list[i]%2)){
      printf("%d\n",list[i]);
    }
  }

  free(list);
  return 0;//free check!!!
}
