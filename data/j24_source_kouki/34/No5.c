#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  
  int i,j,kazu=0,sum=0;
  int **numberbox,**save;

  srand((unsigned)time(NULL));
  
  printf("num=");
  scanf("%d",&kazu);
  numberbox=(int **)malloc(sizeof(int *)*kazu);
  for(i=0;i<kazu;i++){
    numberbox[i]=(int *)malloc(sizeof(int)*kazu);
  }
  
  printf("(1)\n");
  for(i=0;i<kazu;i++){
    for(j=0;j<kazu;j++){
      numberbox[i][j]=rand()%10;
      printf("%d ",numberbox[i][j]);
    }
    printf("\n");
  }

  printf("\n(2)\n");
  for(i=0;i<kazu;i++){
    sum+=numberbox[i][i];
  }
  printf("%d\n",sum);

  printf("\n(3)\n");
  save=(int **)malloc(sizeof(int *)*kazu);
  for(i=0;i<kazu;i++){
    save[i]=(int *)malloc(sizeof(int)*kazu);
  }
  for(i=0;i<kazu;i++){
    for(j=0;j<kazu;j++){
      save[i][j]=numberbox[i][j];
    }
  }
  for(i=0;i<kazu;i++){
    for(j=0;j<kazu;j++){
      numberbox[i][j]=save[j][i];
      printf("%d ",numberbox[i][j]);
    }
    printf("\n");
  }


  free(numberbox);
  free(save);
}
