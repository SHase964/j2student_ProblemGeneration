#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int **numberBox;
  int num;
  int i,c;
  int youso;
  
  printf("何行何列の正方行列にしたい？=");
  scanf("%d",&num);

   srand((unsigned)time(NULL));
   
   numberBox = (int **)malloc(sizeof(int *) *(num+1) );
   for (i=0; i<num; i++) {
     numberBox[i] = (int *)malloc(sizeof(int) *(num+1));
   }
   
   for (i=0; i<num; i++) {
     for (c=0; c<num; c++) {
       numberBox[i][c] =youso;
       if(youso>=num){
	 youso=-1;
       }
       youso++;
	
     }
   }
   
  printf("(1)\n");
  for (i=0; i<num; i++) {
    for (c=0; c<num; c++) {
      printf("%d",numberBox[i][c]);
      printf(" ");
    }
      printf("\n");
  }

  printf("(2)\n");
  for (i=0; i<num; i++) {
    for (c=0; c<num; c++) {
      printf("%d",numberBox[c][i]);
      printf(" ");
    }
    printf("\n");
  }
  
  
  
  
  for (i=0; i<num; i++) {
    free(numberBox[i]);
  }
  free(numberBox);
  
  return 0;
}
