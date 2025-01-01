#include <stdio.h>
#include <stdlib.h>

int main(){
  int num;
  int i;
  char **pt;
  char dummy;
  
  printf("文字列の数を入力\n");
  scanf("%d",&num);

  pt = (char **)malloc(sizeof(char *)*num);

  for(i=0;i<num;i++){
    pt[i] = (char *)malloc(sizeof(char)*10+2);
    fgets(pt[i],10,stdin);
    scanf("%c",&dummy);
    pt[12] = '\0';
    printf("%s\n",pt[i]);
  }

  for(i=0;i<num;i++){
    free(pt[i]);
  }
  free(pt);
  
  return 0;
}
