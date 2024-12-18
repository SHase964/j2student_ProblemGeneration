#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  int **nb;
  int n;
  int drx;
  int t1;
  int ff;
  srand((unsigned int)time(NULL));
  printf("n=");
  scanf("%d",&n);
  nb=(int **)malloc(sizeof(int *)*n);
  for(drx=0;drx<n;drx++){
    nb[drx]=(int *)malloc(sizeof(int)*n);
  }
  for(drx=0;drx<n;drx++){
    free(nb[drx]);
  }
  for(drx=0;drx<n;drx++){
    for(t1=0;t1<n;t1++){
    nb[drx][t1]=rand()%10;
    }
  }
  printf("(1)\n");
  for(drx=0;drx<n;drx++){
    for(t1=0;t1<n;t1++){
      printf("%d ",nb[drx][t1]);
    }
    printf("\n");
  }
  t1=0;
  for(drx=0;drx<n;drx++){
    t1=t1+nb[drx][drx];
  }
  printf("(2)\n%d\n",t1);
   printf("(3)\n");
   for(drx=0;drx<n;drx++){
    for(t1=drx;t1<n;t1++){
      ff=nb[drx][t1];
      nb[drx][t1]=nb[t1][drx];
      nb[t1][drx]=ff;
    }
  }
  for(drx=0;drx<n;drx++){
    for(t1=0;t1<n;t1++){
      printf("%d ",nb[drx][t1]);
    }
    printf("\n");
  }
  free(nb);
  return 0;
}
