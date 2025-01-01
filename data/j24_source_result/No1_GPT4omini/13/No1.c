#include<stdio.h>
#include<stdlib.h>

int main(){
  int a,i,j,save,count=0;
  int *array;
  char dummy;
  int num;
  scanf("%d",&num);
  scanf("%c",&dummy);
  array=(int *)malloc(sizeof(int)*num);
  for(i=0;i<num;i++){
    scanf("%d",&a);
    scanf("%c",&dummy);
    array[i]=a;
  }
  for(i=0;i<num;i++){
    for(j=1;j<num-count;j++){
      if(array[j-1]>=array[j]){
	save=array[j-1];
	array[j-1]=array[j];
	array[j]=save;
      }
    }
    count++;
  }
  printf("\noutput\n\n");
  for(i=0;i<num;i++){
    printf("%d\n",array[i]);
  }
  free(array);
  return 0;
}
