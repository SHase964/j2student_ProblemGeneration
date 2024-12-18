#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int  *hako;
  int a,i;
//  char dummy;

  srand((unsigned)time(NULL));


  printf("(1)\n入力=");

  scanf("%d",&a);
//  scanf("%c",&dummy);
  hako=(int*)malloc(sizeof(int)*a+1);

  for(i=0;i<a;i++){
    hako[i]=rand()%100;
    printf("%d\n",hako[i]);
  }

//  hako[i]=="\0";
  i=i-1;


  printf("\n\n(2)\n");

  while(i>=0){
    printf("%d\n",hako[i]);
    i--;
  }


  i=0;
  printf("\n\n(3)\n");


  while(hako[i]!='\0'){
    if(hako[i]%2==0){
      printf("%d\n",hako[i]);
    }
    i++;
  }


  free(hako);
  return 0;
}
