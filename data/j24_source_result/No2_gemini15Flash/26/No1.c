#include <stdio.h>
#include <stdlib.h>

int main(void){
  char check[100];
  char **str;
  int space = 0;
  int length = 0;
  int k = 0;
  int i = 0;

  fgets(check,100,stdin);
  while(check[i] != '\0'){
    if(check[i] == ' '){
      space++;
    }
    i++;
  }

  i = 0;
  str = (char **)malloc(sizeof(char *) * (space+1));
  while(check[i] != '\0'){
    while(check[i] != ' '){
      length++;
      i++;
    }
    str[k] = (char *)malloc(sizeof(char) * length);
    k++;
  }

  for( i = 0;i < k;i++){
    printf("%s ",str[i]);
  }

  for( i = 0;i < k;i++){
    free(str[i]);
  }
  free(str);
  
  return 0;
}
  
