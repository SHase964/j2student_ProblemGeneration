#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  int **space;
  int large;
  int i, j;
  int n, m;
  char *tmp;
  int checkcount = 0;
  int total = 0;

  srand((unsigned)time(NULL));

  printf("\nInput the number\n");
  printf("行: ");
  scanf("%d", &n);
  printf("列: ");
  scanf("%d", &m);
  large = n * m;

  space = (int **)malloc(sizeof(int)*(large+1));

  for(i=0;i<large;i++) {
    space[i] = (int *)malloc(sizeof(int)*(large+1));
  }

  **space = 0;
  for(i=0; i<n; i++) {
    for(j=0; j<m; j++) {
      space[i][j] = rand()%100;
      total = total + space[i][j];
      checkcount++;
    }
  }
  if(checkcount == 0) {
    printf("1以上の自然数を入力してください\n");
  }

  free(space);

  return 0;
}
