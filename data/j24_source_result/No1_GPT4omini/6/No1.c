#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int func(int *array, int num){
  int i;
  int numbox[num];
  array[0]=numbox[0];
  for(i=1; i<num; i++){
    if(array[i]>=array[i-1]){
       numbox[i] = array[i]
	 }
  }
  return numbox[num/2];
}
int main(void){
  int i;
  int center;
  int num = 0;
  int *array;
  srand((unsigned)time(NULL));
  
  while(num<1){
    scanf("%d", &num);
    printf("配列の文字数を指定してください(自然数)");
  }
  
  array = (int *)malloc(sizeof(int)*num);

  for(i=0;i<num;i++){
    array[i] = rand()%10;
  }
  center = func(array,num);
  printf("%d\n", center);
  free(array);
  return 0;
}
