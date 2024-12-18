#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int len1 = 0;
  int len2 = 0;
  int len3 = 0;
  int count = 0;
  char str1[] = "Kisarazu0000";
  char str2[] = "City0000";
  char *str3;

  while(str1[count] != '\0') {
    len1++;
    count++;
  }
  count = 0;
  while(str2[count] != '\0') {
    len2++;
    count++;
  }
  len3 = len1+len2;
  printf("%d %d %d\n", len1, len2, len3);

  str3 = (char *)malloc(sizeof(char)*(len3+1));

  for(count = 0; count < len3+1; count++) {
    if(count < len1) str3[count] = str1[count];
    else str3[count] = str2[count-len1];
  }
  str3[len3+1] = '\0';

  printf("%s\n", str3);
  
  free(str3);
}
