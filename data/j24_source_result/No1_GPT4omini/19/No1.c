#include<stdio.h>
void nibai(int *new,int *INT);
int main(){
  int *INT;
  int *new;
  scanf("%d",INT);
  printf("Original array:%s\n",INT);
  nibai(new,INT);
  printf("Doubled array:%s\n",INT);
  return 0;
}
void nibai(int *new,int *INT){
  int i,count=0;
  for(i=0;i!='\0';i++){
    count++;
  }
  for(i=0;i<count;i++){
    new[i]=INT[i]*2;
  }
}
