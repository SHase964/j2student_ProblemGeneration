#include<stdio.h>
#include<stdlib.h>

int main (void){
  int i,j,size,num;
  char **box;
  char dum;

  printf("文字列の数 : ");
  scanf("%d",&num);

  box=(char **)malloc(sizeof(char *)*num);

  for(i=0;i<num;i++){
    printf("文字数 : ");
    scanf("%d%c",&size ,&dum);

    box[i]=(char *)malloc(sizeof(char)*size);

    printf("単語を入力 : ");

    scanf("%s",box[i]);
  
  }


  free(box);
  
  return 0;

}