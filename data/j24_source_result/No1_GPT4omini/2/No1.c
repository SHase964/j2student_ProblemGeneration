#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int num;
  scanf("%d", &num);
  int *pt;
  pt = malloc(sizeof(int) * num);

  for(int i = 0; i < num; i++) {
    scanf("%d", &pt[i]);
  

  int val = RAND_MAX;
  int spare;
  int index;
  int i, j;
  for(i = 0; i < num; i++) {
    for(j = 0; i + j < num; j++) {
      if(pt[i + j] < val) {
	val = pt[i + j];
	index = i + j;
      }
    }
    spare = pt[i];
    pt[i] = val;
    pt[index] = spare;
    val = RAND_MAX;
  }
  printf("\n");
  
  double ans;
  if(num % 2 == 0) {
    ans = (double)(pt[i / 2] + pt[i / 2 - 1]) / 2;
  }
  else {
    ans = pt[num / 2];
  }

  printf("%lf\n", ans);
  
  return 0;
}
