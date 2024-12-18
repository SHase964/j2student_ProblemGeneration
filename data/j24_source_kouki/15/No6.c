#include <stdio.h>
#include <stdlib.h>

int main(){
  int NUM;
  int i = 0;
  char *array;
  char str1[] = " Kisarazu";
  char str2[] = " City";

  NUM = snprintf(NULL , 0, "%s", str1) + snprintf(NULL , 0, "%s", str2) - 1 - 1 + 1;
  printf("NUM = %d\n", NUM);

  array = (char*)calloc(NUM+1, sizeof(char));
  array[NUM] = 0;
  
  while(i < snprintf(NULL , 0, "%s", str1)){
    array[i] = str1[i+1];
    i++;
  }

  i--;
  while(i < NUM){
    array[i] = str2[(i -  snprintf(NULL , 0, "%s", str1) + 1) + 1];
    i++;
  }

  printf("%s\n", array);

  free(array);
  return 0;
}
