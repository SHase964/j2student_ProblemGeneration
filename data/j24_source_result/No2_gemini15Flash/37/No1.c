#include<stdio.h>
#include<stdlib.h>


int main(){
  int i,ii,n,num,numa;
  int **box;

  printf("pleas number");
  scanf("%d",&n);

  box=(int **)malloc(sizeof(int *)*n);

  printf("\n");
  num=1;
  for(i=0;i<n;i++){
    box[i]=malloc(sizeof(int  *)*n);
    numa=num+1;
    for(ii=0;ii<n;ii++){
      box[i][ii]=num;
      printf("%d ",box[i][ii]);
      num=num+n;
    }
    printf("\n");
    num=numa;
  }

  for(i=0;i<n;i++){
    free(box[i]);
  }
  free(box);

  return 0;
}
