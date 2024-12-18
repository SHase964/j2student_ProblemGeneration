#include<stdio.h>
#include<stdlib.h>

#define NUM 100
int main(void){
  void *malloc(size_t size);
  int rand(void);
  int i;
  int *pt;
  int n;
  for(n=0;n<100;n++);
  n = rand();
  pt = (char *)malloc(100);
  for(i=0;i<NUM;i++){
    pt[i] = i;
  }
  for(i=0;i<NUM;i++){
    printf("pt[%d]=%d\n",i,pt[i]);
  }
  
    return 0;

}
