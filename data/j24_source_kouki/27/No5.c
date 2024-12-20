#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
  int **pt;
  int sum,i,j,t,size;
  srand((unsigned)time(NULL));
  
  printf("n = ");
  scanf("%d",&size);

  pt=(int **)malloc(sizeof(int *)*size);

  for(i=0;i<size;i++){
    pt[i]=(int *)malloc(sizeof(int)*size);
  }

  printf("(1)\n");
  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      pt[i][j]=rand()%10;
      printf("%d ",pt[i][j]);
    }
    printf("\n");
  }
  sum=0;
  
  printf("(2)\n");
  for(i=0;i<size;i++){
    j=i;  
    sum=sum+pt[i][j];
  }
  printf("%d\n",sum);
  i=j=0;
  
  printf("(3)\n");
  for(i=0;i<size;i++){
    for(j=i+1;j<size;j++){
      t=pt[i][j];
      pt[i][j]=pt[j][i];
      pt[j][i]=t;
    }
  }

  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      printf("%d ",pt[i][j]);
    }
    printf("\n");
  }
  
  for(i=0;i<size;i++){
    free(pt[i]);
  }
  free(pt);

  return 0;
}
