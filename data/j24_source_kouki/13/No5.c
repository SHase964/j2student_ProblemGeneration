#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int **array;
  int flag,sum=0,num,i,j,change;
  char no;
  srand((unsigned)time(NULL));
  printf("n=");
  scanf("%d",&num);
  scanf("%c",&no);
  array=(int **)malloc(sizeof(int *)*num);
  for(i=0;i<num;i++){
    array[i]=(int *)malloc(sizeof(int)*(num+1));
  }
  printf("(1)\n");
  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      array[i][j]=rand()%10;
      printf("%d ",array[i][j]);
    }
    printf("\n");
  }
  printf("(2)\n");
  for(i=0;i<num;i++){
    sum+=array[i][i];
  }
  printf("sum=%d\n",sum);
  printf("(3)\n");
  change=0;
  for(i=0;i<num;i++){
    for(j=change;j>=0;j--){
      flag=array[i][j];
      array[i][j]=array[j][i];
      array[j][i]=flag;
    }
    change++;
  }
  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      printf("%d ",array[i][j]);
    }
    printf("\n");
  }
  for(i=0;i<num;i++){
    free(array[i]);
  }
  free(array);
}
