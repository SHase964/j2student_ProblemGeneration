#include <stdio.h>
#include <stdlib.h>

int mystrlen(char str[])
{
  int len;

  len = 0;
  while(str[len]!='\0') {
    len++;
  }
  return len;
}

int main(void)
{
  char str1[] = "Kisarazu";
  char str2[] = "City";
  char *pt;
  int total;
  int i, j;
  
  total = mystrlen(str1);
  total += mystrlen(str2);
  //printf("%d\n", total);
  pt = (char *)malloc(sizeof(char)*(total+1));

  i = 0;
  while (str1[i]!='\0') {
    pt[i] = str1[i];
    i++;
  }
  j = 0;
  while (str2[j]!='\0') {
    pt[i] = str2[j];
    i++;
    j++;
  }
  pt[i] = '\0';

  printf("%s\n", pt);
  
  free(pt);
  
  return 0;
}
