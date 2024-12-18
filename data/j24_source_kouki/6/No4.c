#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

  int *pt;
  int num;
  int i;
  srand((unsigned)time(NULL));
  
  while(num<1){
    printf("(1) 1以上の整数を入力\n配列の数：");
    scanf("%d" , &num);
  }
  
  pt = (int *)malloc(sizeof(int)*num);

  for(i=0; i<num; i++){
    pt[i] = rand()%100;
    printf("%d\n", pt[i]);
  }

  printf("\n(2)逆順に出力\n");
  for(i=num-1; i>=0; i--){
    printf("%d\n", pt[i]);
  }

  printf("\n(3)偶数だけ出力\n");
  for(i=0; i<num; i++){
    if(pt[i]%2==0){
      printf("%d\n",pt[i]);
    }
  }
    
  free(pt);
  return 0;
}
