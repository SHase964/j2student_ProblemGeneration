#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){

  int ransuu,flag,ans,Key;
  srand((unsigned int)time(NULL));
  flag=1;
  ransuu=rand()%50;
  Key=0;

  int **map;
  int retu,gyo;
  printf("gyo:");
  scanf("%d",&gyo);
  printf("retu:");
  scanf("%d",&retu);

  map=(int**)malloc(sizeof(int*)*gyo);
  for(int i=0;i<gyo;i++) map[i]=(int*)malloc(sizeof(int)*retu);

  for(int i=0;i<gyo;i++){
    for(int j=0;j<retu;j++){
      if(i==gyo-2&&j==retu-1) map[i][j]=5;
      else if(i==0||j==0||i==gyo-1||j==retu-1) map[i][j]=0;
      else map[i][j]=rand()%4+1;
    }
  }

  int x, y;
  int hp=1000;
  int px,py;
  char direction[10],dum,answer[10];
  int anss;
  int dir;
  int player_x = 1,player_y = 1;
  int h,g,d;

	printf("いまここから，あなたの冒険が始まった。\n");
	sleep(1);
	srand((unsigned)time(NULL));
	while (1){

		/* map 表示 */
		printf("\nhp=%d\n",hp);
		y = 0;
		while (y < 20){
			x = 0;
			while (x < 40){
				if (x == player_x && y == player_y){
					printf("@");
				}else{
                                        if(map[y][x] == 0){
						printf("#");
					}else if (map[y][x] == 1){
						printf(" ");
					}else if (map[y][x] == 2){
						printf(" ");
					}else if (map[y][x] == 3){
						printf("=");
					}else if (map[y][x] == 4){
						printf(".");
					}else if (map[y][x] == 5){
						printf("Exit");
					}
				}
				x = x + 1;
			}
			printf("\n");
			y = y + 1;
		}
		if(flag==2){
		    printf("扉が開いた");
		    flag=1;
		    }
		else if(flag==1) printf("どうする？");
		else if(ransuu>ans) printf("もっと大きい\n");
                else if(ransuu<ans) printf("もっと小さい\n");
//デバッグ用
//printf("%s",answer);
		/* プレイヤの移動 */
		printf("> ");
		scanf("%s%c",direction,&dum);
		if((direction[0]>='0')&&(direction[0]<='9')){
		    dir=direction[0]-'0';
		    if (dir == 2){
			px = player_x;
			py = player_y + 1;
		    }
		    else if (dir == 4){
			px = player_x - 1;
			py = player_y;
		    }
		    else if (dir == 6){
			px = player_x + 1;
			py = player_y;
		        }
		    else if (dir == 8){
			px = player_x;
			py = player_y - 1;
		        }
		    }
		else{
		    if (direction[0] == 's'){
			px = player_x;
			py = player_y + 1;
		    }
		    else if (direction[0] == 'a'){
			px = player_x - 1;
			py = player_y;
		    }
		    else if (direction[0] == 'd'){
			px = player_x + 1;
			py = player_y;
		        }
		    else if (direction[0] == 'w'){
			px = player_x;
			py = player_y - 1;
		        }
		    }
		/* そこに壁か扉がない場合は移動できる */
		if ((map[py][px] == 2)||(map[py][px] == 1)){
			player_x = px;
			player_y = py;
		    }
		/* 鍵を拾う */
		if (map[player_y][player_x] == 2){
                    map[player_y][player_x] = 0;
		    Key++;
		    }
//デバッグ用
//ransuu=0;
		for(int i=0;i<10;i++) answer[i]=0;
		/* 通常扉 */
                if (map[py][px] == 3){
		    printf("扉のパスワードを入力(0~49):");
		    scanf("%s%c",answer,&dum);
		    anss=0;
		    ans=0;
		    for(int j=0;j<10;j++){
			if((answer[j]>='0')&&(answer[j]<='9')){
			    anss++;
			    if(anss<=2) ans=ans*10+answer[j]-'0';
			    }
			}
                    if(ransuu==ans){
			player_x = px;
                        player_y = py;
			map[player_y][player_x] = 0;
			flag=2;
			ransuu=rand()%50;
			}
		    else flag=0;
                    }
                if (map[py][px] == 4){
		    printf("damaged:");
		    hp-=rand()%200;
                    }
                if (map[py][px] == 5){
                    if(Key==3){
			printf("脱出成功！！\n");
			return 0;
			}
		    else{
			printf("\n\n鍵が足りないぞ！\n\n");
			}
                    }

	}
}
