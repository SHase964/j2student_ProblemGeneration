#include <stdio.h>
#include <stdlib.h>

int main(){
  int i,mojisu_str1=0,mojisu_str2=0;
  char str1[]="Kisarazu";
  char str2[]="City";
  char *ketu;

  for(i=0;str1[i]!='\0';i++){
    mojisu_str1++;
  }
  for(i=0;str2[i]!='\0';i++){
    mojisu_str2++;
  }
  
  ketu=(char *)malloc(sizeof(char)*(mojisu_str1+mojisu_str2));
  for(i=0;i<mojisu_str1;i++){
    ketu[i]=str1[i];
  }
  for(i=mojisu_str1;i<mojisu_str1+mojisu_str2;i++){
    ketu[i]=str2[i-mojisu_str1];
  }
  printf("%s\n",ketu);
  
  free(ketu);
}
