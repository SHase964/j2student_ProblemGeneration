#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int **numberBox;
  int i, ct;
  int num;

  printf ("num=");
  scanf("%d",&num);


  numberBox = (int **)malloc(sizeof(int *));

  for (i=0; i<9; i++) {
    numberBox[num][num] = ct++;
  }

  for (i=0; i<9; i++) {
    printf("numberBox[%d][%d]=%d\n", num, num, numberBox[num][num]);
  }


  free(numberBox);

  return 0;
}
