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

void main(){

  int i, *pointer, array[10]={}, ave1, ave2;
  char dummy;
  ave1=ave2=0;
  
  pointer=(int *)malloc(sizeof(int)*10);
      
  for(i=0;i<10;i++){

    scanf("%d", &array[i]);
    scanf("%c", &dummy);
    pointer[i]=array[i];

  }

  ascsort(pointer, 10);
  ascsort(&array[0], 10);

  printf("ポインタの最小値は %d\n", pointer[0]);
  printf("配列の最小値は %d\n", array[0]);
  printf("ポインタの最大値は %d\n", pointer[9]);
  printf("配列の最大値は %d\n", array[9]);

  for(i=0;i<10;i++){

    ave1=ave1+pointer[i];
    ave2=ave2+array[i];
  }

  ave1=ave1/10;
  ave2=ave2/10;
  printf("ポインタの平均値は %d\n", ave1);
  printf("配列の平均値は %d\n", ave2);

  if(pointer[0]==array[0] & pointer[9]==array[9] & ave1==ave2){

    printf("よって, 配列を用いた計算結果とポインタを用いた計算結果が一致する.\n");
  }else{
    printf("一致しない");
  }
}

  
    
