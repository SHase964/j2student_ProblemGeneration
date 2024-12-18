#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER    1
#define VISITED   2
#define GOAL      3

void disp_map(int **map, int xsize, int ysize, int hp);
void disp_topbottom_wall(int xsize);
void move(int *px, int *py, int xsize, int ysize);

int main(void)
{
  int **map;        // マップ情報
  int xsize, ysize; // マップの大きさ
  int px,py;        // プレイヤーの位置
  int hp = 1000;    // プレイヤーのHP
  int game = 1;     // ゲームクリア判定
  int x,y;
  int i,j;          //roop
  
  srand((unsigned)time(NULL));
  
  // マップサイズを決定し，動的に確保する
  printf("xsize=");
  scanf("%d", &xsize);
  printf("ysize=");
  scanf("%d", &ysize);
  
  map=(int **)malloc(sizeof(int *)*ysize);
  for(i=0;i<ysize;i++){
    map[i]=(int *)malloc(sizeof(int)*xsize);
  }

  // マップ内に爆弾を仕掛ける
  for(i=0;i<ysize;i++){
    for(j=0;j<xsize;j++){
      map[i][j]=rand()%200+10;
    }
  }
 
  // プレイヤーの初期値
  px = 0;
  py = 0;
  map[py][px] = PLAYER;

  // ゴールの位置
  map[ysize-1][xsize-1] = GOAL;

  while (game) {
    disp_map(map, xsize, ysize, hp);
    
    map[py][px] = VISITED;
    move(&px, &py, xsize, ysize);
    if (10<=map[py][px]) { // define定義していない値のときは
      hp -= map[py][px];
    }
    map[py][px] = PLAYER;
    
    if ((px==xsize-1 && py==ysize-1) || hp<0) {
      game = 0;
    }
  }

  // クリア判定
  if(hp>0){
  printf("\ngame clear!!!\n\n");
  }else{
    printf("\ngameover\n\n");
  }
  // メモリ開放
  for(i=0;i<ysize;i++){
    free(map[i]);
  }
  free(map);
  
  return 0;
}

void disp_map(int **map, int xsize, int ysize, int hp)
{
  int i,j;
  printf("HP:%d\n",hp);
  disp_topbottom_wall(xsize);
  for(i=0;i<ysize;i++){
    printf("|");
    for(j=0;j<xsize;j++){
      if(map[i][j]==1){
	printf("@");
      }else if(map[i][j]==2){
	printf(" ");
      }else if(map[i][j]==3){
	printf("G");
      }else{
	printf("*");
      }
      if(j!=xsize-1){
	printf(" ");
      }
    }
    printf("|\n");
  }
  disp_topbottom_wall(xsize);
}

void disp_topbottom_wall(int xsize)
{
  int i;
  printf("+");
  for(i=0;i<(2*xsize)-1;i++){
    printf("-");
  }
  printf("+\n");
}

void move(int *px, int *py, int xsize, int ysize)
{
  int key;
  char no;
  
  printf("     8:上\n");
  printf("4:左       6:右\n");
  printf("     2:下\n");
  printf("key=");
  scanf("%d", &key);
  scanf("%c",&no);
  if(key==8){
   if(*py!=0){
      *py-=1;
      }
  }else if(key==6){
    if(*px!=xsize-1){
      *px+=1;
      }
  }else if(key==4){
    if(*px!=0){
      *px-=1;
     }
  }else if(key==2){
    if(*py!=ysize-1){
      *py+=1;
      }
  }
}
