#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_LENGTH 0
#define MAX_LENGTH 99

int main(){
  int i;
  int num;
  int rev;

  srand(time(NULL));

  printf ("num=");
  scanf("%d",&num);

  i = 0;
  while (i < 99) {
     = rand();
    
  }

   printf("Reversed array:\n");
    for (int i=0; i<SIZE; i++){
     printf("%d",*(rev+i));
  }
  printf("\n");
  return 0;
}
