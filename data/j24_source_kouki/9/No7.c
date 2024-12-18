#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int x,y;
  printf("x = ");scanf("%d",&x);
  printf("y = ");scanf("%d",&y);
  char **pt;
  pt = (char **)malloc(sizeof(char *) * y);
  for(int i=0;i<y;i++){
    pt[i] = (char *)malloc(sizeof(char) * x);
  }
  /* pt[0][0]='+';
  pt[0][x-1]='+';
  pt[y-1][0]='+';
  pt[y-1][x-1]='+';
  */
  for(int i=0;i<y;i++){
    for(int j=0;j<x;i++){
      printf("%c",pt[i][j]);
    }
    printf("\n");
  }
  
  for(int i=0;i<y;i++){
    free(pt[i]);
  }
  free(pt);


  return 0;
}
  
