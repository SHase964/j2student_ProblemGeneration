#include <stdio.h>
#include <stdlib.h>
int main(){
  int num;
  int drx;
  char *dis;
  char str1[]="Kisarazu";
  char str2[]="City";
  num=0;
  for(drx=0;str1[drx]!='\0';drx++){
    num++;
  }
  for(drx=0;str2[drx]!='\0';drx++){
    num++;
  }
  dis=(char *)malloc(sizeof(char)*num);
  num=0;
  for(drx=0;str1[drx]!='\0';drx++){
    dis[num]=str1[drx];
    num++;
  }
  for(drx=0;str2[drx]!='\0';drx++){
    dis[num]=str2[drx];
    num++;
  }
  printf("%s\n",dis);
  free(dis);
  return 0;
}
