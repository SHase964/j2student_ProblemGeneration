#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  int num;
  int drx;
  int *pt;
  srand((unsigned int)time(NULL));
  printf("kazuha=");
  scanf("%d",&num);
  pt=(int *)malloc(sizeof(int)*num);
  drx=num;
  for(drx=0;drx<num;drx++){
    pt[drx]=rand()%100;
  }
   printf("(1)\n");
  for(drx=0;drx<num;drx++){
    printf("%d\n",pt[drx]);
  }
  printf("(2)\n");
  for(drx=num-1;drx>=0;drx--){
    printf("%d\n",pt[drx]);
  }
  printf("(3)\n");
  for(drx=0;drx<num;drx++){
    if(pt[drx]%2==0){
      printf("%d\n",pt[drx]);
    }
  }
  free(pt);
  return 0;
}
