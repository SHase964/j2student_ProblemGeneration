#include <stdio.h>
#include <stdlib.h>

int mozi_count(char *pt1, char *pt2){
  int i;
  int j;
  int mozi=0;
  for(i=0; pt1[i]!='\0';i++){
    mozi++;
  }
  for(j=0; pt2[j]!='\0';j++){
    mozi++;
  }
  if(i>j){
    printf("%s > %s\n", pt1, pt2);
  }
  else if(j==i){
    printf("%s = %s\n", pt1, pt2);
  }
  else{
    printf("%s < %s\n", pt1, pt2);
  }
    
  return mozi;
}

void hikaku(char *pt1, char *pt2){
  int i;
  for(i=0; pt1!='\0'&&pt2!='\0'; i++){
    if(pt1[i]!=pt2[i]){
      printf("%s != %s\n", pt1, pt2);
      break;
    }
  }
  if(pt1[i]=='\0'&&pt2[i]=='\0'){
    printf("%s = %s\n", pt1, pt2);
  }
}

void ketugou(char *pt1, char *pt2, char **pt3){
      
    int i;
    int j;

    for(i=0; pt1[i]!='\0'; i++){
      *pt3[i] = pt1[i];
    }
    
    for(j=0; pt2[j]!='\0'; j++){
      *pt3[i] = pt2[j];
      i++;
    }
    //*pt3[i] = '\0';
}

int main(void){
  int i;
  int j;
  int mozi;
  char *str1 = "Cafe";
  char *str2 = "Tachyon";
  mozi = mozi_count(str1, str2);
  printf("%d\n", mozi);

  char *str3;
  str3 = (char *)malloc(sizeof(char)*mozi);
  hikaku(str1, str2);
  ketugou(str1, str2, &str3);
  printf("%s\n", str3);
  free(str3);  
  return 0;
}
