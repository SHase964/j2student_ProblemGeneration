#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int *array;
  int i,n;
  int num;
  
  srand((unsigned)time(NULL));
  printf("入力する数=");
  scanf("%d",&num);

  array = (int *)malloc(sizeof(int)*num);
  
  i=0;
  printf("(1)\n");
  while(i<num){
    array[i] = rand()%100;
    printf("%d\n",array[i]);
    i++;
  }
  printf("\n");
   printf("(2)\n");
   while(i>0){
     i--; 
    printf("%d\n",array[i]);  
   }
   printf("\n");
   i=0;n=0;
   printf("(3)\n");
   while(i<num){
     n = array[i]%2;
     if(n == 0){
       printf("%d\n",array[i]);
     }
     i++;
   }
   
   
   free(array);
   return 0;
}
