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

  srand((unsigned)time(NULL));
  
  // マップサイズを決定し，動的に確保する
  printf("xsize=");
  scanf("%d", &xsize);
  printf("ysize=");
  scanf("%d", &ysize);
  
  map = malloc(sizeof(int *) * ysize);
  for(int i = 0; i < ysize; i++) {
    map[i] = malloc(sizeof(int) * xsize);
  }

  // マップ内に爆弾を仕掛ける
  // secret
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
  for(int i = 0; i <ysize; i++) {
    free(map[i]);
  }
  free(map);
  
  return 0;
}

void disp_map(int **map, int xsize, int ysize, int hp) {

  printf("+");
  for(int i = 0; i < xsize * 2; i++) {
    printf("-");
  }
  printf("+\n");
  for(int i = 0; i < ysize; i++) {

    printf("|");
    for(int j = 0; j < xsize; j++) {
      if(map[i][j] == PLAYER) {
	printf("@ ");
      }
      else if(map[i][j] == GOAL) {
	printf("G ");
      }
      else if(i == 0 && j == xsize - 1 || i == ysize - 1 && j == 0) {
	printf(". ");
      }
      else if(i != 0 && j != 0 && map[i][j] != VISITED || i != ysize - 1 && j != xsize - 1  && map[i][j] != VISITED) {
	printf(". ");
      }
      else {
	printf("  ");
      }
    }
    printf("|\n");
  }
  printf("+");
  for(int i = 0; i < xsize * 2; i++) {
    printf("-");
  }
  printf("+\n");
}

void disp_topbottom_wall(int xsize) {
}

void move(int *px, int *py, int xsize, int ysize) {
  int key;
  
  printf("     8:上\n");
  printf("4:左       6:右\n");
  printf("     2:下\n");
  printf("key=");
  scanf("%d", &key);

  if(key == 8) {
    *py--;
  }
  else if(key == 2) {
    *py++;
  }
  else if(key == 4) {
    *px--;
  }
  else {
    *px++;
  }
}
