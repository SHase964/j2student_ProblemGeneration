#include <stdlib.h>
#include <stdio.h>


int main(void){

  int **pt;
  int a,b,c;
  int i,j;


  scanf("%d",&a);
  pt=(int *)malloc(sizeof(int)*a);
  pt=(int)malloc(sizeof(int)*a);

  b=0;
  //while(b==a*a-1){
    for(j=0;j<a;j++){
      pt[i][j]=b;
      b+1;
      printf("%d",pt[i][j]);
    }
    for(i=0;i<a-1;i++){
      pt[i][j]=b;
      b+1;
      printf("%d",pt[i][j]);
    }

    free(pt);
    return 0;
}
    
