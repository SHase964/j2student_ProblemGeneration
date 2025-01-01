#include <stdio.h>
#include <stdlib.h>

int main (){
  int num;
  int i,j,l=0;
  int c=0;
  char **pt;
  

  printf("単語数＝");
  scanf("%d",&num);
  
  pt=malloc(sizeof(char *)*num);

  char wo;
  for(i=0;i<num;i++){
    printf("単語＝");
    scanf("%c",&wo);
    char word[]={wo};
    while(word[l] != '\0'){
      c++;
      l++;
    }
    pt[i]=malloc(sizeof(char)*c);
    
    for(j=0;j<c;j++){
      pt[i][j]=word[j];
	}
  }
  printf("%s\n",pt);
  free(pt);
  return 0;
}
