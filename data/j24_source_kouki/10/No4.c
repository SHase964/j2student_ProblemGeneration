#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){  

  int i;
  int num;
  int *pt;
  
  srand((unsigned)time(NULL));
  printf("array=");
  scanf("%d",&num);
  printf("(1)\n");
  
  pt=(int *)malloc(sizeof(int)*num);
  
  for(i=0;i<num;i++){
    pt[i]=rand()%100;
    printf("%d\n",pt[i]);
  }

  printf("(2)\n");

  for(i=1;i<=num;i++){
    printf("%d\n",pt[num-i]);
  }

  printf("(3)\n");
  int even;
  
  for(i=0;i<num;i++){
    even=pt[i]%2;
    if(even==0){
      printf("even=%d\n",pt[i]);
    }
  }
  
  
  free(pt);
  return 0;
}
