#include <stdio.h>
#include <stdlib.h>

int main(void){

  int array1[3] = {1,3,5};
  int array2[3] = {2,4,6};
  int *array_sum;
  int count1,count2;
  int i;

  count1 = count2 = 0;
  for(i=0;array1[i]!='\0';i++){
    count1++;
  }
  for(i=0;array2[i]!='\0';i++){
    count2++;
  }

  array_sum = (int *)malloc(sizeof(int)*(count1+count2));

  for(i=0;array_sum[i]!='\0';i++){
    array_sum[i] = array1[i];
    array_sum[i+1] = array2[i];
  }

  for(i=0;array_sum[i]!='\0';i++){
    printf("%d",array_sum[i]);
  }
  printf("\n");

  free(array_sum);

  return 0;

}

  
