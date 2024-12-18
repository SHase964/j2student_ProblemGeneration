#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void output(int **A,int n,char a[]){

  int len;
  for(len=0;a[len]!='\0';len++);

  for(int i=0;i<n;i++){

    if(i==n/2) printf("%s=",a);
    else for(int j=0;j<=len;j++) printf(" ");

    if(i==0&&n>1) printf("/");
    else if(i==n-1&&n>1) printf("\\");
    else if(n==1) printf("(");
    else printf("|");

    for(int j=0;j<n;j++) printf("%d ",A[i][j]);

    if(i==0&&n>1) printf("\\");
    else if(i==n-1&&n>1) printf("/");
    else if(n==1) printf(")");
    else printf("|");

    printf("\n");
  }
}

int main(){

  int **A;
  int *dum;
  int n;
  srand((unsigned)time(NULL));

  printf("input n:");
  scanf("%d",&n);

  printf("(1)\n");
  A=(int**)malloc(sizeof(int*)*n);
  for(int i=0;i<n;i++) A[i]=(int*)malloc(sizeof(int)*n);
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) A[i][j]=rand()%10;
  output(A,n,"A");

  printf("(2)\n");
  int sum=0;
  for(int i=0;i<n;i++) sum+=A[i][i];
  printf("sum=%d\n",sum);

  printf("(3)\n");
  dum=(int*)malloc(sizeof(int)*n);
  for(int i=0;i<n*2-1;i++){
    for(int j=0;j<=i;j++) if(j<n&&i-j<n) dum[j]=A[j][i-j];
    for(int j=0;j<=i;j++) if(j<n&&i-j<n) A[i-j][j]=dum[j];
  }
  output(A,n,"tA");

  free(dum);
  for(int i=0;i<n;i++) free(A[i]);
  free(A);
}
