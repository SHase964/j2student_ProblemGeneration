#include <stdio.h>
#include <stdlib.h>

int main(){
  int i,j;
  int **pt;
  int num;

  scanf("%d",&num);
  if(num<0){
    printf("0以上で入力して下さい\n");
    return 0;
  }
  pt=(int **)malloc(sizeof(int *)*num);
  for(i=0;i<num;i++){
    pt[i]=(int *)malloc(sizeof(int)*num);
  }

  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      pt[i][j]=i*num+j;
      printf("%3d",pt[i][j]);
    }
    printf("\n");
  }

  for(i=0;i<num;i++){
    free(pt[i]);
  }
  free(pt);
}
