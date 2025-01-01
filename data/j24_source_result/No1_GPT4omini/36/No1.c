#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  int *array;
  int  mux;
  int  min;
  int n;
  int i, j;
  int num;
  int p = -1;
  int q = -1;

  printf ("入力する文字数を入力してください\n文字数=");
  scanf("%d", &n);

  array = (int *)malloc(sizeof(int) *n+1);
  //mux = (int *)malloc(sizeof(int) *n+1);
  //n = (int *)malloc(sizeof(int) *n+1);

  printf("\n数字を入力してください\n");
  for(i=0; i<n; i++) {
    printf("%d番目=", i+1);
    scanf("%d", &num);
    array[i] = num;
    mux = num;
    min = num;
    if (mux < array[i]) {
      mux = array[i];
      p = i;
    }
    if (min > array[i]) {
      min = array[i];
      q = i;
    }
  }
  printf("入力\n");
  for(j=0; j<n; j++) {
    printf("%d\n", array[j]);
  }

  printf("出力\n");
  printf("最大値： %d\n", mux);
  printf("最小値； %d\n", min);
  printf("最大値のインデックス： %d\n", p);
  printf("最小値のインデックス： %d\n", q);
  

  free(array);
  return 0;
}
