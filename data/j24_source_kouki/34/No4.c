#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  
  int i,kazu=0;
  int *pt;
  
  srand((unsigned)time(NULL));
  
  printf("num=");
  scanf("%d",&kazu);
  pt=(int *)malloc(sizeof(int)*kazu);

  printf("(1)\n");
  for(i=0;i<kazu;i++){
    pt[i]=rand()%100;
    printf("%d\n",pt[i]);
  }

  printf("\n(2)\n");
  for(i=0;i<kazu;i++){
    printf("%d\n",pt[kazu-i-1]);
  }

  printf("\n(3)\n");
  for(i=0;i<kazu;i++){
    if(pt[i]%2==0){
      printf("%d\n",pt[i]);
    }
  }
  printf("\n");
  
  free(pt);
}
