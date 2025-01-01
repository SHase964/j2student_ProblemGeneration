#include<stdio.h>
#include<stdlib.h>

int main(){
  int i,num,j,count,sum;
  int **array;
  char dummy;
  num=-100;
  while(1>num){
    scanf("%d",&num);
    scanf("%c",&dummy);
  }
  array = (int **)malloc(sizeof(int *)*num);
  for(i=0;i<num;i++){
    array[i]=(int *)malloc(sizeof(int)*num);
  }
  count=0;
  printf("\n");
  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      count++;
      array[i][j]=count;
      printf("%3d ",array[i][j]);
    }
    printf("\n");
  }
  printf("\nsum of collum\n\n");
  for(i=0;i<num;i++){
    sum=0;
    for(j=0;j<num;j++){
      sum+=array[i][j];
    }
    printf("%d\n",sum);
  }
  for(i=0;i<num;i++){
    free(array[i]);
  }
  free(array);
}
