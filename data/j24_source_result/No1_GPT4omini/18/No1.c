#include <stdio.h>
#include <stdlib.h>


int ran(int Min, int Max){
  
  int random;
  random=rand();
  return random%(Max-Min+1)+Min;
}

void ascsort(int *bubble, int num){

    int i, j, tmp;

    while(num>1){

        for(i=0;i<num-1;i++){

            if(bubble[i]>bubble[i+1]){

                tmp=bubble[i+1];
                bubble[i+1]=bubble[i];
                bubble[i]=tmp;
            }
        }
        num=num-1;
    }

}

int main(){

  int i, *array, youso;

  printf("要素数を入力してください.\n");
  scanf("%d", &youso);

  array=(int *)malloc(sizeof(int)*youso);
  printf("(1)\n");
  
  for(i=0;i<youso;i++){

    array[i]=ran(0, 99);
    printf("%d\n", array[i]);

  }

  printf("(2)\n");

  ascsort(array, youso);

  printf("%d\n", array[0]);
  printf("%d\n", array[youso-1]);

  printf("(3)\n");

  for(i=0;i<youso;i++){

    printf("%d\n", array[i]);

  }

  free(array);
}
  
