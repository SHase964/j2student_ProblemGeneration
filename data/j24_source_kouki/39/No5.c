#include<stdio.h>
#include<stdlib.h>
#include<time.h>


/* void func1(int array[][],int x);
   void func2(int array[][],int x);
*/
int main(void)
{
  int **matrix;
  int num,i,j;

  srand((unsigned)time(NULL));
  
  printf("Input num = ");
  scanf("%d",&num);

  matrix = (int **)malloc(sizeof(int *)* num);

  for(i=0;i<num;i++)
    {
      matrix[i] = (int *)malloc(sizeof(int *)* num);
    }
  for(i=0;i<num;i++)
    {
      for(j=0;j<num;j++)
	{
	  matrix[i][j] = rand() % 9;
	}
    }

  printf("(1)\n");
  for(i=0;i<num;i++)
    {
      for(j=0;j<num;j++)
	{
	  printf("%d ",matrix[i][j]);
	}
      printf("\n");
    }
  

  //func1(matrix,num);
  //func2(matrix,num);

  for(i=0;i<num;i++)
    {
      free(matrix[i]);
    }
  free(matrix);

  return 0;
}

/*void func1(int array[][],int x)
{
  int i,j,val;
  i = j = val = 0;
  
  for(i=0;i<x;i++)
    {
      for(j=0;j<x;j++)
	{
	  if(i == j)
	    {
	      val += array[i][j];
	    }
	}
    }
}
*/