#include <stdio.h>
#define NUM 3
#define BOM 2

int main(void)
{
  int array[NUM]={3,1,4};
  int arry[BOM]={2,5};
  int ary [NUM+BOM];
  int i,k,d;
  
  for(i=0; i<NUM; i++){
    ary[i]=array[i];
  }

  for(k=0; k<BOM; k++){
    ary[i]=arry[k];
  }

  for(i=0; i<5; i++){
    if(ary[i]<ary[i+1]){
      ary[i]=ary[i+1];
    }
  }

  printf("\n");
  for(i=0; i<NUM+BOM; i++){
  printf("%d",ary[i]);
  }
    
    
    
  

                      






  return 0;
}
