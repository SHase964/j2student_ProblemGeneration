#include<stdio.h>
#include<stdlib.h>
int main(){
  int NUM,i=0,j,SUM=0;
  int **pt;
  int **copy;
  printf("NUM=");
  scanf("%d",&NUM);
  printf("(1)\n");
  // while(i<16){
  //  printf("%d",rand()%10);
  //  i++;
  //}
  /*順番通りに数が入っているかの確認*/
  pt = (int **)malloc(sizeof(int *)*NUM);
  for(i=0;i<NUM;i++){
    pt[i] = (int *)malloc(sizeof(int)*NUM);
  }
  for(i=0;i<NUM;i++){
    for(j=0;j<NUM;j++){
      pt[i][j]=rand()%10;
    }
  }
  for(i=0;i<NUM;i++){
    for(j=0;j<NUM;j++){
      printf("%d ",pt[i][j]);
    }
    printf("\n");
  }
  printf("(2)対角成分の和\n");
  for(i=0;i<NUM;i++){
    SUM += pt[i][i];
  }
  printf("SUM=%d\n",SUM);
  printf("(3)転置行列\n");
   copy = (int **)malloc(sizeof(int *)*NUM);
  for(i=0;i<NUM;i++){
    copy[i] = (int *)malloc(sizeof(int)*NUM);
  }
  for(i=0;i<NUM;i++){
    for(j=0;j<NUM;j++){
      copy[i][j]=pt[j][i];
    }
  }
  //  for(i=0;i<NUM;i++){
  //  for(j=0;j<NUM;j++){
  //    printf("%d ",copy[i][j]);
  //  }
  // printf("\n");
  //}
  /*copyが正常に転置行列になっているかの確認*/
  for(i=0;i<NUM;i++){
    for(j=0;j<NUM;j++){
      pt[i][j]=copy[i][j];
    }
  }
  for(i=0;i<NUM;i++){
    for(j=0;j<NUM;j++){
      printf("%d ",pt[i][j]);
    }
    printf("\n");
   }

  for(i=0;i<NUM;i++){
    free(pt[i]);
    free(copy[i]);
  }
  free(pt);
  free(copy);
  return 0;
}

