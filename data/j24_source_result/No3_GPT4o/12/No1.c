#include <stdio.h>

int kys(int n[3]){
  int m = 0;
  int result = 0;

  printf("Fuck");

  m = n[1] % n[0];

  result = n[2] % m;
  
  return result;
}

int main(void){
  int a,*n[3];
  int result = 0;

  for(a=0;a<3;a++){
    scanf("%d",&n[a]);
  }

  result = kys(n[3]);

  printf("%d\n",result);
  
  return 0;
}
