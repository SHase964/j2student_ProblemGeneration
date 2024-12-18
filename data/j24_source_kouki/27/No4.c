#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (void){
  int *pt;
  int i,size;

  srand((unsigned)time(NULL));
  printf("input number : ");
  scanf("%d",&size);

  pt=(int *)malloc(sizeof(int)*size);

  printf("(1)\n");
  for(i=0;i<size;i++){
    
    pt[i]=rand()%100;
    printf("pt[%d]=%d\n",i,pt[i]);
    
  }

  printf("(2)\n");
  for(i=size-1;i>=0;i--){

    printf("pt[%d]=%d\n",i,pt[i]);

  }

  printf("(3)\n");
  for(i=0;i<size;i++){

    if(pt[i]%2==0){

      printf("pt[%d]=%d\n",i,pt[i]);

    }
  }
    
  free(pt);
  return 0;
}
  
