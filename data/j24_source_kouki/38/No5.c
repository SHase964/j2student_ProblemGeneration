#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

  int i,j,a;
  int total;
  int **pt;

  scanf("%d",&a);
  
  pt=(int **)malloc(sizeof(int *)*a);

  total=0;
  printf("(1)\n");
  for(i=0;i<a;i++){
    pt[i]=(int *)malloc(sizeof(int)*a);
    for(j=0;j<a;j++){
      pt[i][j]=rand()%10;
      printf("%d",pt[i][j]);
    }
    printf("\n");
  }

  printf("\n");
  printf("(2)\n");
  for(i=0;i<a;i++){
    for(j=0;j<a;j++){
      if(i==j){
	total=total+pt[i][j];
      }
    }
  }
  printf("%d\n",total);

  printf("\n");
  printf("(3)\n");
  for(i=0;i<a;i++){
    for(j=0;j<a;j++){
      printf("%d",pt[j][i]);
    }
    printf("\n");
  }

  
  free(pt);
  return 0;
}
