#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int n,a,s,u;
  int **fn;

  printf("Enter NUM\n");
  scanf("%d",&n);

  fn = (int **)malloc(sizeof(int *)*(n-1));

  srand((unsigned)time(NULL));

  printf("(1)\n");

  for(a=0;a<n;a++){
    for(s=0;s<n;s++){
      fn[a][s] = rand()%10;
      printf("%d",fn[a][s]);
    }
    printf("\n");
  }

  printf("(2)\n");

  u = 0;

  for(a=0;a<n;a++){
    u = fn[a][a] + u;
  }

  printf("%d\n",u);

  free(fn);
  
  return 0;
}
