#include <stdio.h>
#include <stdlib.h>

int main(void) {

  char str1[] = "Kisarazu";
  char str2[] = "City";

  int ct1 = 0, ct2 = 0;

  int i = 0;
  while(str1[i] != '\0') {
    ct1++;
    i++;
  }
  
  i = 0;
  while(str2[i] != '\0') {
    ct2++;
    i++;
  }

  char *pt;
  pt = malloc(sizeof(char) * (ct1 + ct2));

  i = 0;
  for(i = 0; i < ct1; i++) {
    pt[i] = str1[i];
  }
  for(i = 0; i < ct2; i++) {
    pt[i + ct1] = str2[i];
  }

  printf("%s\n", pt);
  
  free(pt);
  return 0;
}
