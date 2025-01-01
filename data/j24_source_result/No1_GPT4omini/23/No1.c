#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
  srand((unsigned)time(NULL));
  int *pt;
  int *pt2;
  int len = 5;
  int len2 =0;
  int flug =0;
  pt = (int*)malloc(sizeof(int)*len);

  len2=len;

  for(int i=0;i<len;i++){
    pt[i] = rand()%10;
  }

  for(int i=0 ;i<len;i++){
  printf("%d ",pt[i]);
  }
  printf("\n");

  for(int i=0;i<len;i++){
    for(int j=i+1;j<len;j++){
      if(pt[i] == pt[j]){
        pt[j] = -1;
        flug++;
      }
    }
  }


  for(int i=0 ;i<len;i++){
  printf("%d ",pt[i]);
  }
    printf("\n");
  printf("%d\n",len2);


  return 0;
}
