#include<stdio.h>
#include<stdlib.h>

int moji_len(char *str){
  int i=0;
  while(str[i]!='\0'){
    i++;
  }
  return i;
}
void ketsugo(char *res,char *str,int *c,int st_len){
  int i;
  for (i=0;i<st_len;i++){
    res[i+*c]=str[i];
  }
  *c=i;
}


int main(void){
  char str1[]="Kisarazu";
  char str2[]="City";
  char *res;
  int c=0;
  int len1=moji_len(str1);
  int len2=moji_len(str2);
  printf("1:%d 2:%d \n",len1,len2);
  res=(char *)malloc(sizeof(char)*(len1+len2)+1);
  res[len1+len2]='\0';
  ketsugo(res,str1,&c,len1);
  printf("%d\n",c);
  ketsugo(res,str2,&c,len2);
  printf("%s\n",res);
  free(res);
  return 0;//free!!!!
}
