#include<stdio.h>
#include<stdlib.h>

int main(){
  char str1[]="SAZANAMI";
  char str2[]="E257";
  int sum=0,i;
  char *array;
  while(str1[i]!='\0'){
    sum++;
    i++;
  }
  i=0;
  while(str2[i]!='\0'){
    sum++;
    i++;
  }
  array=(char *)malloc(sizeof(char)*(sum+1));
  sum=0;
  i=0;
  while(str1[i]!='\0'){
    array[sum]=str1[i];
    i++;
    sum++;
  }
  i=0;
  while(str2[i]!='\0'){
    array[sum]=str2[i];
    i++;
    sum++;
  }
  printf("%s\n",array);
  free(array);
}
