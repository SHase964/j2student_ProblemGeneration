#include<stdio.h>
#include<stdlib.h>
int main(void){
     int **pt;
     int i,p,a;

     printf("数字を入力してください＝");
     scanf("%d",&a);
     pt=(int**)malloc(sizeof(int*)*(a));

     for(i=0;i<a;i++){
       pt[i]=(int*)malloc(sizeof(int*)*(a));
       for(p=0;p<a;p++){
         pt[i][p]=p+1;
       }
       printf("%s\n",pt[i]);
     }


     for(i=0;i<a;i++){
       free(pt[i]);
     }



     free(pt);
     return 0;
}
