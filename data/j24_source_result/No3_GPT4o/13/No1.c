#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
  int i,j,save,num,ans,count,check,flag;
  int *array;
  char dummy;
  printf("Please enter the long of array.\nlong=");
  scanf("%d",&num);
  count=num;
  scanf("%c",&dummy);
  printf("Please enter the number of sarch.\nanswer=");
  scanf("%d",&ans);
  scanf("%c",&dummy);
  printf("\nOutput\n");
  array=(int *)malloc(sizeof(int)*num);
  for(i=0;i<num;i++){
    array[i]=i*i;
  }
  for(i=0;i<num;i++){
    count--;
    for(j=0;j<count;j++){
      if(array[j]>array[j+1]){
	save=array[j];
	array[j]=array[j+1];
	array[j+1]=save;
      }
    }
  }
  printf("%d ",array[0]);
  check=array[0];
  flag=0;
  for(i=1;i<num;i++){
    printf("%d ",array[i]);
    if(abs(ans-array[i])<abs(ans-check)){
      check=array[i];
      flag=i;
    }
  }
  printf("\n");
  printf("Index:%d\n",flag);
  free(array);
  return 0;
}
