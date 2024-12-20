#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ran(int Min, int Max){     

  int random;
  random=rand();
  return random%(Max-Min+1)+Min;
}

int main(){

  srand((unsigned)time(NULL));
  
  int **array, i, j, dim, sum, **tmp;

  sum=0;

  printf("正方行列の次数を入力してください.\n");
  
  scanf("%d", &dim);
  
  printf("(1)\n");
  if(dim==0){
    return 0;
  }
  
  array=(int **)malloc(sizeof(int *)*dim);

  for(i=0;i<dim;i++){

    array[i]=(int *)malloc(sizeof(int)*dim);
    for(j=0;j<dim;j++){
      array[i][j]=ran(0, 9);
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }

  printf("(2)\n");

  for(i=0;i<dim;i++){

    sum=sum+array[i][i];
  }
  printf("%d\n", sum);

  printf("(3)\n");

  tmp=(int **)malloc(sizeof(int *)*dim);

  for(i=0;i<dim;i++){

    tmp[i]=(int *)malloc(sizeof(int)*dim);
    for(j=0;j<dim;j++){
      tmp[i][j]=array[i][j];
    }
  }

  for(i=0;i<dim;i++){

    for(j=0;j<dim;j++){
      array[i][j]=tmp[j][i];
    }
  }

  for(i=0;i<dim;i++){

    for(j=0;j<dim;j++){
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }

  for(i=0;i<dim;i++){

    free(array[i]);
    free(tmp[i]);
  }

  free(array);
  free(tmp);

}

  


  

  
