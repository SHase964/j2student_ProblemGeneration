#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printmatrix(int **numberbox,int n){
  for(int j=0; j<n; j++){
    for(int i=0;i < n; i++){
      printf("%d ",numberbox[j][i]);
    }
    printf("\n");
  }
}

int main(void){

  srand((unsigned)time(NULL));

  int **numberbox;
  int n = 3;
  int cul = 0;

  printf("n = %d\n",n);

    numberbox = (int **)malloc(sizeof(int) * n);
    for(int i=0; i<n; i++){
    numberbox[i] = (int *)malloc(sizeof(int) * n);
    }



    for(int j=0; j<n; j++){
      for(int i=0;i < n; i++){
        numberbox[j][i] = rand()%10;
        if(i == j)cul += numberbox[j][i];
      }
    }

    printf("(1)\n");
    printmatrix(numberbox, n);


    printf("(2)\n");
    printf("cul = %3d\n",cul);


    int tempb,tempa;
    int tempn = n;
    int tempn2=0;
    for(int j=0; j<n; j++){
      for(int i=0;i < tempn; i++){
        tempb = numberbox[j][i+tempn2];
        tempa = numberbox[i+tempn2][j];
        numberbox[j][i+tempn2] = tempa;
        numberbox[i+tempn2][j] = tempb;
      }
      tempn--;
      tempn2++;
    }



    printf("(3)\n");
    printmatrix(numberbox, n);





  free(numberbox);
  return 0;
}
