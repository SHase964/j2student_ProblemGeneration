#include <stdio.h>
#include <stdlib.h>


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

  int *bubble, i;
  char dummy;
  
  bubble=(int *)malloc(sizeof(int )*3);

  for(i=0;i<3;i++){

    scanf("%d", &bubble[i]);
    scanf("%c", &dummy);
    
}

  
  ascsort(bubble, 3);

  for(i=0;i<3;i++){

    printf("%d\n", bubble[i]);
  }
}