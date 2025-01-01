#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *pt;
  int n;
  int min=0,max=0;
  printf("num = ");scanf("%d",&n);

  pt = (int *)malloc(sizeof(int) * n);
  pt[0]=0;
  for(int i=0;i<n;i++){
    printf("pt[%d] = ",i);
    scanf("%d",&pt[i]);
  }

  max = pt[0];
  for(int i=0;i<n;i++){
    max = (max<pt[i]) ? pt[i] : max;
  }
  min = pt[0];
  for(int i=0;i<n;i++){
    min = (min>pt[i]) ? pt[i] : min;
  }

  printf("max: %d\nmin: %d\n",max,min);
 
  return 0;
}
