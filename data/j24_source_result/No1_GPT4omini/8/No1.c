#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(void)
{
  int array[SIZE];
  int i,num,max,a,min,b;
  
  printf("nyuryoku\nnum=");
  scanf("%d",&num);
 
  for (i=0; i<SIZE; i++) {
    array[i] = rand()%num;
    printf("a[%d]=%d\n",i,array[i]);
  }
  printf("\nsyuturyoku\n");

  max=0; min=num;
  for (i=0; i<SIZE; i++) {
    if(max<array[i]){
      max=array[i];
	a=i;
    }
    if(min>array[i]){
      min=array[i];
	b=i;
    }
  }
  
  printf("max[%d]=%d\n",a,max);
  printf("min[%d]=%d\n",b,min);
  
  return 0;
}
