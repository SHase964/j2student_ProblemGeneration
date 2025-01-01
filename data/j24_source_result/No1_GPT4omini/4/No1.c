#include<stdio.h>
#include<stdlib.h>

int main(void) {
  int *pt;
  int num = 0;
  int input = 0;
  int stand = 0;
  int repeat = 0;

  printf("Please input the number you will input.\n");
  scanf("%d",&num);
  pt = (int *)malloc(sizeof(int)*num);

  printf("Input number whatever you like %d times.\n", num);
  for(int count = 0; count < num; count++) {
    scanf("%d",&input);
    pt[count] = input;
  }

  while(repeat < num) {
    for(int count = 0; count < num-1; count++) {
      if(pt[count] > pt[count+1]) {
	stand = pt[count];
	pt[count] = pt[count+1];
	pt[count+1] = stand;
      }
    }
    repeat++;
  }

  printf("After sorting: ");
  for(int count = 0; count < num; count++) printf("%d ",pt[count]);
  printf("\n");
}
