#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void func1(char *pt)
{
  int i,num;

  srand((unsigned)time(NULL));

  i = 0;
  while(pt[i+1] != '\0')
    {
      pt[i] = rand() % 99;
      i++;
    }
  printf("(1)\n");
  i = 0;
  while(pt[i+1] != '\0')
    {
      printf("array[%d] = %d\n",i,pt[i]);
      i++;
    }
}

void func2(char *pt)
{
  int i;
  i = 0;
  while(pt[i+2] != '\0')
    {
      i++;
    }
  printf("(2)\n");
  while(i >=  0)
    {
      printf("array[%d] = %d\n",i,pt[i]);
      i -= 1;
    }
}

void func3(char *pt)
{
  int i,n;
  i = n = 0;
  printf("(3)\n");
  while(pt[i+1] != '\0')
    {
      n = pt[i] % 2;
      if(n == 0)
	{
	  printf("array[%d] = %d\n",i,pt[i]);
	}
      i++;
    }
}

int main(void)
{
  char *array;
  char *pt;
  int num;

  printf("Input num = ");
  scanf("%d",&num);

  array = (char *)malloc(sizeof(char)*(num+1));
  array[num+1] = '\0';
  pt = array;

  func1(pt);
  func2(pt);
  func3(pt);

  free(array);

  return 0;
}
  
