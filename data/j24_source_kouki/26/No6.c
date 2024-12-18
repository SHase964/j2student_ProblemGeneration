#include <stdio.h>
#include <stdlib.h>

int main(void){
  char *str1;
  char *str2;
  char *str;
  int num1;
  int num2;
  char dummy;

  printf("input the str1 length : ");
  scanf("%d",&num1);
  scanf("%c",&dummy);
  
  str1 = (char *)malloc(sizeof(char) * (num1+1));

  printf("input the letter : ");
  fgets(str1, num1+1, stdin);

  printf("\ninput the str2 length : ");
  scanf("%d",&num2);
  scanf("%c",&dummy);
  
  str2 = (char *)malloc(sizeof(char) * (num2+1));
  
  printf("input the letter : ");
  fgets(str2, num2+1, stdin);

  str = (char *)malloc(sizeof(char) * (num1+num2+1));
  for(int i = 0;i < )

  printf("\nAll str : %s\n",str);

  free(str1);
  free(str2);
  
  return 0;
}
