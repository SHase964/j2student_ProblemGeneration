#include<stdio.h>
#include<stdlib.h>


int main(void)
{
  int num;
  int **matrix,i,j,n;

  n=0;

  printf("Input num = ");
  scanf("%d",&num);

  matrix = (int **)malloc(sizeof(int *)*(num));
  
  for(i=0;i<num;i++)
    {
      matrix[i] = (int *)malloc(sizeof(int)*(num));
    }

  for(i=0;i<num;i++)
    {
      for(j=0;j<num;j++)
	{
	  matrix[i][j] = n;
	  n++;
	}
    }

  for(i=0;i<num;i++)
    {
      for(j=0;j<num;j++)
	{
	  printf("%d ",matrix[i][j]);
	}
      printf("\n");
    }

    for(i=0;i<num;i++)
    {
      free(matrix[i]);
    }

    free(matrix);

  return 0;
}
