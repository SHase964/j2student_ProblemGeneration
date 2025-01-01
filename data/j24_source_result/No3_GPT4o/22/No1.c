#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int **ma1;
  int **ma2;
  int i,j,k,m,n;


  printf("Input Number = ");
  scanf("%d",&n);

  ma1 = (int **)malloc(sizeof(int *)*n);
  for(m=0;m<n;m++){
    ma1[m] = (int *)malloc(sizeof(int )*n);
  }

  printf("行列A\n");
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	ma1[j][k] = rand()%10;
	printf("%3d",ma1[j][k]);
      }
    printf("\n");
    }
  }
  ma2 = (int **)malloc(sizeof(int *)*n);
  for(m=0;m<n;m++){
    ma2[m] = (int *)malloc(sizeof(int )*n);
  }
  
printf("行列B\n");
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	ma2[j][k] = rand()%10;
	printf("%3d",ma1[j][k]);
      }
    printf("\n");
    }
  }
  
  printf("和\n");
  for(j=0;j<n;j++){
    for(k=0;k<n;k++){
      ma1[j][k] = ma1[j][k] + ma2[j][k];
      printf("%3d",ma2[j][k]);
    }
    printf("\n");
  }
  
  free(ma1);
  free(ma2);

  return 0;

}
