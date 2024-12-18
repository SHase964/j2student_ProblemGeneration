#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char str1[]="Kisarazu";
  char str2[]="City";
  int len = sizeof(str1)/sizeof(str1[0]) + sizeof(str2)/sizeof(str2[0]) -1;
  char *pt;

  pt = (char *)malloc(sizeof(char) * len);

  int i=0;
  while(str1[i]!='\0'){
    pt[i] = str1[i];
    i++;
  }
  int j=i;
  i=0;
  while(str2[i]!='\0'){
    pt[j] = str2[i];
    j++;
    i++;
  }
  pt[j]='\0';
  printf("%s\n",pt);
  
  free(pt);


  return 0;
}
  
