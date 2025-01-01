#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
#define MAX 999
#define MIN 0



int main(void){
  int *num,*sort;
  int i,a,m,p;
  int res;
  num=(int *)malloc(sizeof(int)*SIZE);
  sort=(int *)malloc(sizeof(int)*SIZE);
  for(i=0;i<SIZE;i++){
    scanf("%d",num+i);
  }
  for (i=0;i<SIZE;i++){
    res=res+num[i];
  }
  printf("all:%d\n",res);


  a=0;
  while (1){
    res=MAX+1;
    for (int i=a;i<SIZE;i++){
      if(num[i]<res){
	res=num[i];
	p=i;
      }
    }
    
    if(res==MAX+1){
      break;
    }
    num[p]=MAX+1;
    sort[a]=res;
    a++;
    for(i=0;i<SIZE;i++){
      printf("%d ",sort[i]);
      
    }printf("\n\n");
    
  }
  printf("min:%d\n",sort[0]);
  printf("max:%d\n",sort[SIZE-1]);
  for (i=0;i<SIZE;i++){
    printf("%d ",sort[i]);
  }
  printf("\n");
  free(sort);
  free(num);

  return 0;
}
