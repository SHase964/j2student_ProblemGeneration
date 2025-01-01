#include <stdio.h>
#include <stdlib.h>
int main(){
  int num;
  int drx;
  int *pt;
  int dex1;
  int dex2;
  printf("mny");
  scanf("%d",&num);
  pt=(int *)malloc(sizeof(int)*num);
  for(drx=0;drx<num;drx++){
     printf("[drx]=");
  scanf("%d",&pt[drx]);
  }
   printf("(1)\n");
  for(drx=0;drx<num;drx++){
    printf("%d\n",pt[drx]);
  }
  printf("(2)\n");
  dex1=0;
  for(drx=0;drx<num;drx++){
    dex1=dex1+pt[drx];
  }
  dex1=dex1/num;
  printf("%d\n",dex1);
  dex1=pt[0];
    dex2=pt[0];
  for(drx=0;drx<num;drx++){
    if(dex1<pt[drx]){
      dex1=pt[drx];
    }
    if(dex2>pt[drx]){
      dex2=pt[drx];
    }
  }
  printf("(3)\nmax=%d\nmin=%d\n",dex1,dex2);
  free(pt);
  return 0;
}
