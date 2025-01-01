#include <stdio.h>
#include <stdlib.h>


int kurabe(int *a){
  int i,b,kazu;
  b=0;

  for(i=0;a!=\0;i++){
     if(a[i]>b){
       b=a[i];
       kazu=i;
     }
  }
  *a=b;
  return kazu;
}

int main(void){
  int a,p,kazu;

  scanf("%s",&a);
  kazu=kurabe(&a);
  printf("最大=%d\nインデックス＝%d",&a,kazu);

return 0;
}
