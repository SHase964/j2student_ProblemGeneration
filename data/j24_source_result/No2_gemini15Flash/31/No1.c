#include<stdio.h>
#include<stdlib.h>


int main(void){
  int **Box;
  int i,j,k,n;
  char dummy;

  scanf("%d",&i);
  scanf("%c",&dummy);
  printf("\n");

  Box=(int **)malloc(sizeof(int *)*i);
  for(j=0;i>j;j++){
    Box[j]=(int *)malloc(sizeof(int)*i);
  }

  for(n=0;n<i;n++){
    for(k=0;k<i;k++){
      Box[n][k]=n+k;
      printf("%2d",Box[n][k]);
    }
    printf("\n");
  }
   free(Box);
  return 0;
}
