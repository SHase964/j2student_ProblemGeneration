#include <stdio.h>
#include <stdlib.h>

int main(){
  int num;
  int i;
  int j;
  int **pt;

  printf("自然数＝");
  scanf("%d",&num);
  
  pt=malloc(sizeof(int *)*num);

  for(i=0;i<num;i++){
    pt[i]=malloc(sizeof(int)*num);
  }

  int c=1;
  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      pt[i][j]=c;
      printf("%2d",pt[i][j]);
      c++;
    }
    printf("\n");
  }
  free(pt);
  return 0;
}
