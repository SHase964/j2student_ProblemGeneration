#include<stdio.h>
#include<stdlib.h>

void func_1(char *arraya[],char *arrayb[],char *arrayc[])
{
  int i,n,m;
  i = n = m = 0;

  if(arraya[i] != '\0' && arrayb[n] != '\0')
    {
      while(m%2 == 0)
	{
	  arrayc[m] = arraya[i];
	  i++;
	}
      while(m%2 == 1)
	{
	  arrayc[m] = arrayb[n];
	  n++;
	}
      m++;
    }
}

int main()
{
  int numa,numb,i,j;
  char *arraya;
  char *arrayb;
  char *arrayc;

  printf("1つめの文字列の文字数を入力してください = ");
  scanf("%d",&numa);

  printf("2つめの文字列の文字数を入力してください = ");
  scanf("%d",&numb);

  arraya = (char *)malloc(sizeof(char)*(numa+1));
  arrayb = (char *)malloc(sizeof(char)*(numb+1));
  arrayc = (char *)malloc(sizeof(char)*(numa+numb+1));

  printf("1つめの文字列を入力してください = ");

  for(i=0;i<numa+1;i++)
    {
      arraya[i] = 1;
    }
  arraya[numa+1] = '\0';
  i=0;
  while(arraya[i] != '\0')
    {
      scanf("%c",&arraya[i]);
      i++;
    }

  printf("2つめの文字列を入力してください = ");

  for(i=0;i<numb+1;i++)
    {
      arrayb[i] = 1;
    }
  arrayb[numb+1] = '\0';
  i=0;
  while(arrayb[i] != '\0')
    {
      scanf("%c",&arrayb[i]);
      i++;
    }

  for(i=0;i<numa+numb+1;i++)
    {
      arrayc[i] = 1;
    }
  arrayc[numa+numb+1] = '\0';

  func_1(char *arraya,char *arrayb,char *arrayc);

  printf("%s\n",arrayc);

  free(arraya);
  free(arrayb);
  free(arrayc);
  

  return 0;
}
  
  
