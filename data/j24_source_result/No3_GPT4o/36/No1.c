#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *array;
  int mux;
  int min;
  int n, num;
  int i;

  printf("入力する文字数を入力してください\n文字数=");
  scanf("%d", &n);

  array = (int *)malloc(sizeof(int) *n+1);

  printf("\n値を入力してください\n");
  for(i=0; i<n; i++) {
    printf("%d番目=", i+1);
    scanf("%d", &num);
    array[i] = num;
    if(i == 0) {
      mux = num;
      min = num;
    }
    if(mux < array[i]) {
      mux = array[i];
    }
    if(min > array[i]) {
      min = array[i];
    }
  }

  printf("\n最大値: %d", mux);
  printf("\n最小値: %d\nXXS", min);

  free(array);
  return 0;
}
