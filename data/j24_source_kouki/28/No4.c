#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int i;
  int ransu;
  int num;
  int *pt;
  int *ptr;



  printf("確保したい配列の数は?=");
  scanf("%d",&num);
  
  
  pt=(int *)malloc(sizeof(int)*(num+1));
  ptr=(int *)malloc(sizeof(int)*(num+1));

  
  srand((unsigned)time(NULL));

  printf("(1)\n");
  for(i=0;i<num;i++){
    ransu=rand()%100;
   *(pt+i)=ransu;
   printf("%d\n",*(pt+i));
  }

  printf("(2)\n");
  for(i=0; i<num; i++){
    *(ptr+i)=*(pt+num-1-i);
  }
  for(i=0; i<num; i++){
    printf("%d\n",*(ptr+i));
  }

  printf("(3)\n");

  for(i=0;i<num;i++){
    if(*(pt+i)%2==0){
      printf("%d\n",*(pt+i));
    }
  }
 

 



  free(pt);
  free(ptr);

  return 0;
}
		   
		   
		   
		   
		   
