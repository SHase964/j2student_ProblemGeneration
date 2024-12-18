#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
  int i;
  int num;
  int j;
  int **pt;
  
  srand((unsigned)time(NULL));
  
  printf("num=");
  scanf("%d",&num);
  printf("(1)\n");
  pt=(int **)malloc(sizeof(int *)*num);
  
  for(i=0;i<num;i++){
    pt[i]=(int *)malloc(sizeof(int)*num);
    for(j=0;j<num;j++){
      pt[i][j]=rand()%10;
      printf("%d",pt[i][j]);
    }
    printf("\n");
  }

  printf("(2)\n");
  int total=0;
  for(i=0;i<num;i++){
    printf("%d+",pt[i][i]);
    total=total+pt[i][i];
  }
  printf("=%d\n",total);

  printf("(3)\n");
  int **box;
  box=(int **)malloc(sizeof(int *)*num);

  for(i=0;i<num;i++){
    box[i]=(int *)malloc(sizeof(int)*num);
    for(j=0;j<num;j++){
      box[i][j]=pt[j][i];
    }
  }
  
  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      pt[i][j]=box[i][j];
      printf("%d",pt[i][j]);
    }
    printf("\n");
  }
  
  free(box);
  free(pt);
  return 0;
}
