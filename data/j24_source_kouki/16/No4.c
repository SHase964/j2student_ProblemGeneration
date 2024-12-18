#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
  int i;
  int a=0;
  int b=0;
  int *num;
  
  scanf("%d", &i);

  num = (int *)malloc(sizeof(int)*i);
  
  srand((unsigned)time(NULL));

  printf("(1)");
  for(a=1; a<=i; a++){
    *(num+a) = rand()%100;
    printf("%3d ", num[a]);
  }
  printf("\n");

  printf("(2)");
  for(a=i; a>0; a--){
    printf("%3d ", num[a]);
  }
  printf("\n");
  

  printf("(3)");
  for(a=1; a<=i; a++){
    if(num[a]%2==0){
      printf("%3d ", num[a]);
    }
  }
  printf("\n");

  free(num);
  
  return 0;

}
