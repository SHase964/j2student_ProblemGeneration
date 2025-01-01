#include <stdio.h>
#include <stdlib.h>

int main(void){

  int num;
  printf("input to number\n");
  scanf("%d",&num);

  int **array;
  array = (int **)malloc(sizeof(int*)*num);
  for(int i=0; i <num; i++){
    array[i] = (int *)malloc(sizeof(int)*num);
  }

  int ans1 = 1;
  printf("matrix\n");
  for(int i=0; i<num; i++){
    for(int j=0; j<num; j++){
      array[i][j] = ans1;
      printf("%d ",array[i][j]);
      ans1++;
    }
    printf("\n");
  }

  int ans2;
  printf("total of line\n");
  for(int i=0; i<num; i++){
    for(int j=0; j<num; j++){
      ans2 = ans2 + array[i][j];
    }
    printf("%d\n",ans2);
    ans2 = 0;
  }

  free(array);
  return 0;
}
