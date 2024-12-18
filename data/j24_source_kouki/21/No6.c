#include <stdio.h>
#include <stdlib.h>

int main(){

  char str1[] = "Kisarazu";
  char str2[] = "City";

  char *str3;

  int i=0;
  int count1,count2;
    
  while(str1[i]!='\0'){
    count1 ++;
    i++;
  }
  
  i=0;
  while(str2[i]!='\0'){
    count2 ++;
    i++;
  }

  str3 = (char *)malloc(sizeof(char)*(count1+count2)+1);

  for(i=0;i<count1;i++){
    str3[i] = str1[i];
  }
  
  for(;i<(count1+count2);i++){
    str3[i] = str2[i-count1];
  }

  str3[i] = '\0';

  printf("%s\n",str3);

  free(str3);

  return 0;
}
