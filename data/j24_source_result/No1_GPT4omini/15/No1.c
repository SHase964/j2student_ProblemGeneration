#include <stdio.h>
#include <stdlib.h>

int main(){
  int *num1;//for all
  int *num2;//for odd
  int *num3;//or even 
  int array_num1 = 0;//for all
  int array_num2 = 0;//for odd
  int array_num3 = 0;//for even
  int i = 0;//for all
  int j = 0;//for odd
  int k = 0;//for even;

  printf("array_num you want to make = "); 
  scanf("%d",&array_num1);

  printf("\nall num\n");
  num1 = (int*)calloc(array_num1,sizeof(int));

  for(i = 0; i < array_num1; i++){
    num1[i] = i;
    printf("num1[%d] = %d\n", i, num1[i]);
    
    if(num1[i] % 2 == 1){
      array_num2++;
    }
    else{
      array_num3++;
    }
  }

  num2 = (int*)calloc(array_num2,sizeof(int));
  num3 = (int*)calloc(array_num2,sizeof(int));

  for(i = 0; i < array_num1; i++){
      
    if(num1[i] % 2 == 1){
      num2[j] = num1[i];
      j++;
    }
    else{
      num3[k] = num1[i];
      k++;
    }
  }

  printf("\nodd_num\n");
  for(j = 0; j < array_num2; j++){
    printf("num2[%d] = %d\n", j, num2[j]);
  }

   printf("\neven_num\n");
  for(k = 0; k < array_num3; k++){
    printf("num3[%d] = %d\n", k, num3[k]);
  }
  
  free(num1);
  free(num2);
  free(num3);
  return 0;
}
