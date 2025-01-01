#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
  int num = 0;
  int sequence = 0;
  int **ptpt;

  printf("Please enter a number above 0!\n");
  while(num == 0) {
    scanf("%d", &num);
    if(num > 0) ;
    else num = 0;
  }
  
  ptpt = (int **)malloc(sizeof(int *)*num);
  for(int count = 0; count < num; count++) {
    ptpt[count] = (int *)malloc(sizeof(int)*num);    
  }

  for(int y = 0; y < num; y++) {
    for(int x = 0; x < num; x++) {
      ptpt[y][x] = sequence;
      sequence++;
    }
  }
  
  for(int y = 0; y < num; y++) {
    for(int x = 0; x < num; x++) {
      printf("%d ", ptpt[y][x]);
    }
    printf("\n");
  }
}
