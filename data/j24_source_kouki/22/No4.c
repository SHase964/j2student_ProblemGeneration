#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){

  int *pt;
  int i,n;
  
  srand((unsigned)time(NULL));

  printf("input number = ");
  scanf("%d",&n);

  pt = (int *)malloc(sizeof(int)*n);

  printf("(1)\n");
  for(i=0;i<n;i++){
    pt[i] = rand()%100;
    printf("pt[%d] = %d\n",i,pt[i]);
  }

  printf("(2)\n");
  while(i>0){
    i -= 1;
    printf("pt[%d] = %d\n",i,pt[i]);
  }

  printf("(3)\n");
  for(i=0;i<n;i++){
    if(pt[i]%2 == 0){
      printf("%d\n",pt[i]);
    }
  }

  free(pt);

  return 0;
  
}
    
