#include<stdio.h>
#include<stdlib.h>
int main(){
  char **Word;
  char *check;
  int i,n,dummy;
  int count;
  printf("単語数を入力してください");
  scanf("%d%d",&n,&dummy);
  Word=(char **)malloc(sizeof(char *)*n);
  scanf("%d",*check);
  printf("%s",check);
  for(i=0;check[i]!='\0';i++){
    count=i+1;
    printf("!!!\n");
  }
  Word[n]=(char *)malloc(sizeof(char)*count);
  
  //  printf("%s",Word[0]);
  return 0;
}
