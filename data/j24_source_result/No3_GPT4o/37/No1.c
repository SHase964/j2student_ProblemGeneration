#include<stdio.h>
#include<stdlib.h>

int main(){
  int len,i,ii,n;
  char *mozi,*dummy,must,hikaku;

  printf("文字数を入力してください\n");
  scanf("%d",&len);
  scanf("%c",&dummy);

  mozi=(char *)malloc(sizeof(char)*len+1);

  printf("文字列を入力してください\n");
  fgets(mozi,len+1,stdin);

  n=1;
  for(ii=0;ii<len;ii++){
    hikaku=mozi[ii];
    for(i=1;i<len;i++){
      if(must==hikaku){
        n++;
	must=hikaku;
      }
    }
  }
      
    

  printf("%s",mozi);
  free(mozi);
  return 0;
}
