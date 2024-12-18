#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int i,j,k;
  int *array;

  printf("input number = ");
  scanf("%d",&k);
  
  array = (int *)malloc(sizeof(int)*k);

  srand((unsigned)time(NULL));

  printf("(1)\n");
  for(i=0; i<k; i++){
    array[i]=rand()%100;
    printf("%d\n",array[i]);
  }

  printf("(3)\n");
  for(i=0; i<k; i++){
    if(array[i]%2==0){
      printf("%d\n",array[i]);
    }
  }
  i--;
  
  printf("(2)\n");
  while(k>0){
    array[k] = array[i];
    printf("%d\n",array[k]);
    i--;
    k--;
    }


  return 0;


}

  
