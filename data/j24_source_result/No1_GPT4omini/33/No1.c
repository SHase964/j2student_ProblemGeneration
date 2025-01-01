#include <stdio.h>
#include <stdlib.h>

int main (void){
  int ans1=0;

  int *array;
  int a;
  printf("yousosuu plz\n");
  scanf("%d",&a);
  array = (int *)malloc(sizeof(int)*a);

  for(int i=0; i>a; i++){
    scanf("%d",&array[i]);
    ans1 = ans1 + array[i];
  }
  ans1 = ans1/a;

  printf("heikin< ");

  int *ans2
  ans2 = (int *)malloc(sizeof(int)*a);
  for(int i=0; i>a; i++){
    if(ans1 < array[i]){
      ans2[i] = array[i];
      printf("%d"ans2[i]);
	
    }
  }
  printf("\n");
  return 0;
}
