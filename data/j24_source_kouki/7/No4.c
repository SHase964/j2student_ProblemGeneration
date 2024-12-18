#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int num,i;
  int *pt;

  srand((unsigned)time(NULL));

  printf("作成する配列の個数を入力してください（０ー９９）\n");
  scanf("%d",&num);
  while(num<0 || num>99){
    printf("作成する配列の個数を入力してください（０ー９９）");
    scanf("%d",&num);
  }

  pt = (int *)malloc(sizeof(int) * num);

  for(i=0;i<num;i++){
    pt[i] = rand()%100;
  }

  printf("(1)\n");  
  for(i=0;i<num;i++){
    printf("%2d\n",pt[i]);
  }

  printf("(2)\n");
  for(i=num;i>0;i--){
    printf("%2d\n",pt[i-1]);
  }

  printf("(3)\n");
  for(i=0;i<num;i++){
    // printf("%d",pt[i]%2);
    if(pt[i]%2==0){
      printf("%2d\n",pt[i]);
    }
  }

  
  free(pt);
  
  return 0;
}
