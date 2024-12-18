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
  int x,y,i;

  srand((unsigned)time(NULL));
  
  // マップサイズを決定し，動的に確保する
  printf("xsize=");
  scanf("%d", &xsize);
  printf("ysize=");
  scanf("%d", &ysize);
  
   map = (int **)malloc(sizeof(int *) *xsize);
  for(i=0;i<xsize;i++){
   map[i] = (int *)malloc(sizeof(int) *ysize);
  }

  // マップ内に爆弾を仕掛ける
  
  // secret
  // secret
  // secret
  // secret
 
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
  // secret
  // secret
  // secret
  // secret
  // secret
  // secret

  // メモリ開放
  // secret
  // secret
  // secret
  // secret
  
  return 0;
}

void disp_map(int **map, int xsize, int ysize, int hp)
{
  // secret 37行
}

void disp_topbottom_wall(int xsize)
{
  // secret 7行
}

void move(int *px, int *py, int xsize, int ysize)
{
  int key;
  
  printf("     8:上\n");
  printf("4:左       6:右\n");
  printf("     2:下\n");
  printf("key=");
  scanf("%d", &key);

  // secret 23行
  
}
