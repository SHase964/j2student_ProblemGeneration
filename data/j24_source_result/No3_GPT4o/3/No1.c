#include <stdio.h>
#include <stdlib.h>
int main(void){
  int a,i,min,max;
  int *kazu;
  min=1;
  max=0;

  printf("サイズ=");
  scanf("%d",&a);


  kazu=(int *)malloc(sizeof(char)*(a+1));

  for(i=0;i<a;i++){
    printf("数=");
    scanf("%d",&kazu[i]);

    if(min>kazu[i]){
      min=kazu[i];
    }
    else if(max<kazu[i]){
      max=kazu[i];
    }

  }


  printf("min=%d\n",min);
  printf("max=%d\n",max);

  free(kazu);

  return 0;
}

