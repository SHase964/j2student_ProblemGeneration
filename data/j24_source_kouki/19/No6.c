#include<stdio.h>
#include<stdlib.h>
int main(){
  int NUM,i,count1=0,count2=0,SUM=0;
  char str1[]="Kisarazu";
  char str2[]="City";
  char *combine;
  printf("(1)\n");
  for(i=0;str1[i]!='\0';i++){
    count1++;
    SUM++;
  }
  printf("str1[%s]:%d\n",str1,count1);
  for(i=0;str2[i]!='\0';i++){
    count2++;
    SUM++;
  }
  printf("str2[%s]:%d\n",str2,count2);
  printf("SUM:%d\n",SUM);
  combine = (char *)malloc(sizeof(char)*SUM);
  for(i=0;i<count1+1;i++){
    combine[i]=str1[i];
  }
  for(i=count1;i<SUM+1;i++){
    combine[i]=str2[i-count1];
  }
  combine[SUM] = '\0';
  printf("combine:%s\n",combine);
  free(combine);
  return 0;
}
