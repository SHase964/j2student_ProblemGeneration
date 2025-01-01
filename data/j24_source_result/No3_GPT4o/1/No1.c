#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char *numberBox;
  int i,j, num,a, col;
  char dummy;

  int row[col];

    printf("how many mozi number?\n");
    scanf("%d%c",&a,&dummy);
    numberBox = (char *)malloc(sizeof(char) *(a+1));
    printf("what's word?\n");
    fgets(numberBox,a+1,stdin);

 
   printf("%s",numberBox);
   printf("\n");

   j=0;
   for(i=0;i>a+1;i++){
     if(numberBox[i] == 'a'){
       j=j+1;
     }
     else if(numberBox[i] == 'i'){
       j=j+1;
     }
     else if(numberBox[i] == 'u'){
       j=j+1;
     }
     else if(numberBox[i] == 'e'){
       j=j+1;
     }
     else if(numberBox[i] == 'o'){
       j=j+1;
     }
   }

   printf("%d\n",j);
  

  free(numberBox);

  return 0;
}
