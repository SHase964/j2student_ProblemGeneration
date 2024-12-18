#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ran(int Min, int Max){     

  int random;
  random=rand();
  return random%(Max-Min+1)+Min;
}

void main(){
  
  int *pw;
  int word, i;
  srand((unsigned)time(NULL));
  
  scanf("%d", &word);
  
  
  pw = (int *)malloc(sizeof(int) * word);

  printf("(1)\n");
  
  for(i=0;i<word;i++){
    pw[i]=ran(0, 99);
  }
  for(i=0;i<word;i++){
    printf("%d ", pw[i]);
  }
  printf("\n");

  printf("(2)\n");
  
  for(i=word-1;i>=0;i--){
    printf("%d ", pw[i]);
}
  
  printf("\n(3)\n");
  for(i=0;i<word;i++){

    if(pw[i]%2==0){

      printf("%d ", pw[i]);
      
    }
  }
  printf("\n");

  free(pw);
}
