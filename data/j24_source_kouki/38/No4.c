#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

  int i,a,b;
  int *pt;

  scanf("%d",&a);
  printf("\n");

  srand((unsigned)time(NULL));
  pt=(int *)malloc(sizeof(int)*a);


  printf("(1)\n");
  for(i=0;i<a;i++){
    pt[i]=rand()%100;
    printf("%d\n",pt[i]);
  }


  printf("\n");
  printf("(2)\n");
  for(i=0;i<a;i++){
    printf("%d\n",pt[a-1-i]);
  }

  printf("\n");
  printf("(3)\n");
  for(i=0;i<a;i++){
    if(pt[i]%2==0){
      printf("%d\n",pt[i]);
    }
  }
  
  free(pt);
  return 0;
}
