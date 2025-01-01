#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
  int *box;
  int max,min,size,i,j;
  double ave;
  
  printf("要素の個数 : ");
  scanf("%d",&size);

  box=(int *)malloc(sizeof(int)*size);
  

  for(i=size-1;i>=0;i--){
    printf("それぞれの数 : ");
    scanf("%d",&j);
    box[i]=j;
  }
  max=min=box[0];
  for(i=0;i<size;i++){
    if(max<box[i]){
      max=box[i];
    }
    if(min>box[i]){
      min=box[i];
    }
    ave=ave+box[i];
  }
  ave=(double)ave/size;
  printf("average : %f\n",ave);
  printf("max : %d\n",max);
  printf("min : %d\n",min);

  free(box);

  return 0;
}
