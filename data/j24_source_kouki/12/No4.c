#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int u,n,k,o;
  int *array1;

  srand((unsigned)time(NULL));

  printf("Enter Num\n");
  scanf("%d",&u);

  array1 = (int *)malloc(sizeof(int)*(u+1));

  int array2[u];

  printf("(1)\n");
  
  for(n=0;n<u;n++){
    array1[n] = rand()%100;
    printf("array1[%d] = %2d\n",n,array1[n]);
  }

  printf("\n(2)\n");

  n = 0;

  for(k=u-1;k>=0;k--){
    array2[k] = array1[n];
    printf("array2[%d] = %2d\n",k,array2[k]);
    n++;
  }

  printf("\n(3)\n");

  for(n=0;n<u;n++){
    o = array1[n]%2;
    if(o==0){
      printf("array1[%d] = %2d\n",n,array1[n]);
    }
    o = 0;
  }

  free(array1); 
  
  return 0;
  
}
