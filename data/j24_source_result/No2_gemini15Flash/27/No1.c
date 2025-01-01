#include<stdio.h>
#include<stdlib.h>

int main(void){
  int leng,word,i,j,num;
  char *sent;
  char dummy;

  leng=word=i=j=0;
  
  printf("文章の文字数を入力（スペースを含む） : ");
  scanf("%d%c",&num ,&dummy);

  sent=(char *)malloc(sizeof(char)*(num+1));

  printf("英語の文章を入力\n");
  fgets(sent,num+1,stdin);

  while(sent[i]!='\0'){
    printf("word: ");
    while(sent[i]!=' '){
      printf("%c",sent[i]);
      leng++;
    }
    if(sent[i]==' '){
      printf(", Lengs: %d\n",leng);
      leng=0;
    }
    i++;
  }

  // printf("%s",sent);

  free(sent);
  return 0;
}
