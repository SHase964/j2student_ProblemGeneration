#include <stdio.h>
#include <stdlib.h>

int* sosuu(int* num){

  int flag,j,k=1,len;
  int *ret;
  unsigned int i;

  for(len=0;num[len]!=0;len++);

  ret=(int*)malloc(sizeof(int)*len+1);

  ret[0]=0;

  for(j=0;num[j]!=0;j++){
    flag = 1;
    if (num[j]<2) {
      flag = 0;
    }
    for (i=2;i*i<=num[j];i++) {
      if(num[j]%i==0) {
        flag=0;
      }
    }
    if(flag){
      ret[0]++;
      ret[k]=num[j];
      k++;
    }
  }

  free(ret);
  return ret;

}

int main(){

  int *num;
  int len;
  int *ret;

  printf("input length:");
  scanf("%d",&len);

  num=(int*)malloc(sizeof(int)*len);
  for(int i=0;i<len;i++) num[i]=0;

  printf("input:");
  for(int i=0;i<len;i++) scanf("%d",&num[i]);
  ret=sosuu(num);

  printf("num:%d\n",ret[0]);
  for(int i=1;i<=ret[0];i++) printf("%d\n",ret[i]);

  free(num);
  free(ret);

}
