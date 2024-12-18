#include<stdio.h>
#include<stdlib.h>

int main(void)
{

  char str1[] = "TOKYO";
  char str2[] = "disneyresort";

  char *pt,*pt1,*pt2;
  int i,j,num;

  i = j = num = 0;

  while(str1[i+1] != '\0')
    {
      i++;
    }
  while(str2[j+1] != '\0')
    {
      j++;
    }

  num = i + j;

  pt = (char *)malloc(sizeof(char) * (num+1));

  pt1 = str1;
  pt2 = str2;

  pt = pt1;

  pt[i] = pt2;

  printf("str1 = %s\n",str1);
  printf("str2 = %s\n",str2);
  printf("pt   = %s\n",pt);

  free(pt);

  return 0;
}
  
