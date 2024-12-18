#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char *pt;
  char str1[]="Kisarazu";
  char str2[]="City";
  int   i,len,a,b;
  
  i=0;
  while(str1[i] != '\0'){
    i++;
  }
  a=i;
  printf("a=%d\n",a);
  
  i=0;
  while(str2[i] != '\0'){
       i++;
  }
  b=i;
  printf("b=%d\n",b);
   
  len=a+b;
  printf("len=%d\n",len);
  pt = (char *)malloc(sizeof(char) *len);
  
   // nyuu力
   for(i=0;i<a;i++){
    pt[i]=str1[i];
  }
    for(i=0;i<b;i++){
    pt[i+a]=str2[i];
  }
    
  printf("ans=%s\n",pt);
  
  free(pt);
  
  return 0;
}
