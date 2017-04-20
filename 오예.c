#include<stdio.h>
#include<windows.h>
#include<stdlib.h> 
#include<time.h>
#include<string.h>

void clear(int x, int y);                //화면클리어 
void space(int px, int py);              //스페이스바(뿅 
int spaceclear(int px, int py);          //뿅 제거 
int up(int x, int y);                    //위로 
int down(int x, int y);                  //아래로 
int right(int x, int y);                 //오른쪽 
int left(int x, int y);                  //왼쪽 
void box(int xbox, int ybox);            //박스 
void gotoxy(int x, int y);               //좌표로가는함수 
void color(int a);                       //출력색깔 
void mbox(int xmbox, int ymbox);         //몬스터박스 
void over();                             //게임오버  
void mclear(int xmbox, int ymbox);       //몬스터박스 클리 

int main(int argc, char* argv[]){
	
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo); // 커서 없에기 
    
   	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 15); // 색깔입히 
   	
   	
	srand(time(NULL));
	
	int randn = rand();
	int boxsp=0, xbox, ybox, hitbox[70][20]={0};
	int mx=0, my=0;
	int x=32, y=19;
	int px, py=-2;
	int ch, qcolor=10;
	int i=1, j=2, h=0;
	int score=0, upg=0;
	int mmbox=0, ymbox=15, xmbox=20;
	int dead[300][100]={0};
	int test=-1,q = 72;
	int count = 1000;
	int tick=1;                   //50 0.05 = 1tick
	
	printf("┌──────────────────────────────────┐\n"); //0
	printf("│                                                                    │\n"); //1
	printf("│                                                                    │\n"); //2
	printf("│                                                                    │\n"); //3 
	printf("│                                                                    │\n"); //4
	printf("│                                                                    │\n"); //5 
	printf("│                                                                    │\n"); //6 
	printf("│                                                                    │\n"); //7
	printf("│                                                                    │\n"); //8
	printf("│                                                                    │\n"); //9
	printf("│                                                                    │\n"); //10 제한 
	printf("│                                                                    │\n"); //11
	printf("│                                                                    │\n"); //12
	printf("│                                                                    │\n"); //13
	printf("│                                                                    │\n"); //14
	printf("│                                                                    │\n"); //15
	printf("│                                                                    │\n"); //16
	printf("│                                                                    │\n"); //17
	printf("│                                                                    │\n"); //18
	printf("│                              ");
   	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
	printf("  △");
   	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 15);
	printf("                                  │\n"); //19
	printf("│                              ");
   	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
	printf("◁■▷");
   	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 15);
	printf("                                │\n"); //20
	printf("│                                                                    │\n"); //21
	printf("│                                                                    │\n"); //22
	printf("│                                                                    │\n"); //23
	printf("│                                                                    │\n"); //24
	printf("│                                                                    │\n"); //25
	printf("│                                                                    │\n"); //26
	printf("│                                                                    │\n"); //27
	printf("└──────────────────────────────────┘\n"); //28
//          19 32
//          20 37 
//          22 38
	gotoxy(72,0);
	printf("┌─────────────────┐\n");
	gotoxy(72,1);
	printf("│                                  │\n");
	gotoxy(72,2);
	printf("│          S  C  O  R  E           │\n");
	gotoxy(72,3);
	printf("│                                  │\n");
	gotoxy(72,4);
	printf("│                0                 │\n");
	gotoxy(72,5);
	printf("│                                  │\n");
	gotoxy(72,6);
	printf("└─────────────────┘\n");
	gotoxy(72,13);
	printf("                조작법               ");
	gotoxy(72,16);
	printf("           ←,→,↑,↓- 방향키        ");
	gotoxy(72,18);
	printf("           SpaceBar - 피융          ");
	gotoxy(72,20);
	printf("           ESC - 종료            ");
	
	
	while(1){
		gotoxy(72,21);
		printf("  ");
		if(dead[x][y] == 1 || dead[x][y+1] == 1
		||  dead[x+1][y] == 1  || dead[x+1][y+1] == 1 
		||  dead[x+2][y] == 1  || dead[x+2][y+1] == 1
		||  dead[x+3][y] == 1  || dead[x+3][y+1] == 1
		||  dead[x+4][y] == 1  || dead[x+4][y+1] == 1
		||  dead[x+5][y] == 1  || dead[x+5][y+1] == 1){
			gotoxy(72,21);
			over();
		}
		if(tick%20==0){
			mclear(xmbox,ymbox);
			dead[xmbox][ymbox-1]=0;
			dead[xmbox+1][ymbox-1]=0;
			dead[xmbox+2][ymbox-1]=0;
			dead[xmbox+3][ymbox-1]=0;
			dead[xmbox+4][ymbox-1]=0;
			dead[xmbox-1][ymbox-1]=0;
			dead[xmbox-2][ymbox-1]=0;
			dead[xmbox][ymbox]=0;
			dead[xmbox+1][ymbox]=0;
			dead[xmbox+2][ymbox]=0;
			dead[xmbox+3][ymbox]=0;
			dead[xmbox+4][ymbox]=0;
			dead[xmbox-1][ymbox]=0;
			dead[xmbox-2][ymbox]=0;
			dead[xmbox][ymbox+1]=0;
			dead[xmbox+1][ymbox+1]=0;
			dead[xmbox+2][ymbox+1]=0;
			dead[xmbox+3][ymbox+1]=0;
			dead[xmbox+4][ymbox+1]=0;
			dead[xmbox-1][ymbox+1]=0;
			dead[xmbox-2][ymbox+1]=0;
			if(xmbox>=62){
				xmbox -= 4;
			}else if(xmbox<=5){
				xmbox += 4;
			}else if(ymbox>=24){
				ymbox -=3;
			}else if(ymbox<=10){
				ymbox +=3;
			}else{
				mmbox = rand()%4 + 1;
				if(mmbox==1){
					xmbox += 4;
				}else if(mmbox==2){
					xmbox -= 4;
				}else if(mmbox==3){
					ymbox += 3;
				}else ymbox -= 3;
			}
			dead[xmbox][ymbox-1]=1;
			dead[xmbox+1][ymbox-1]=1;
			dead[xmbox+2][ymbox-1]=1;
			dead[xmbox+3][ymbox-1]=1;
			dead[xmbox+4][ymbox-1]=1;
			dead[xmbox-1][ymbox-1]=1;
			dead[xmbox-2][ymbox-1]=1;
			dead[xmbox][ymbox]=1;
			dead[xmbox+1][ymbox]=1;
			dead[xmbox+2][ymbox]=1;
			dead[xmbox+3][ymbox]=1;
			dead[xmbox+4][ymbox]=1;
			dead[xmbox-1][ymbox]=1;
			dead[xmbox-2][ymbox]=1;
			dead[xmbox][ymbox+1]=1;
			dead[xmbox+1][ymbox+1]=1;
			dead[xmbox+2][ymbox+1]=1;
			dead[xmbox+3][ymbox+1]=1;
			dead[xmbox+4][ymbox+1]=1;
			dead[xmbox-1][ymbox+1]=1;
			dead[xmbox-2][ymbox+1]=1;
			mbox(xmbox, ymbox);
		}
		if(tick%150==0){
			ybox = (rand() % 6) + 3;
			xbox = (rand() % 58) + 7;
			box(xbox, ybox);
			hitbox[xbox][ybox]=1;
		}                               //표적 & 히트판정 
		if(py>1 && tick%2+1==2){
			space(px, py);
			if(hitbox[px][py]==1 || hitbox[px+1][py] == 1 || hitbox[px-1][py] == 1){
				hitbox[px][py]=0;
				hitbox[px+1][py]=0;
				hitbox[px-1][py]=0;
				score += 50;
				gotoxy(90,4);
				color(9);
				printf("%d",score);
				if(score>=3000){
					qcolor=12;
				}else if(score>=1000){
					qcolor=13;
				}else if(score>=500){
					qcolor=14;
				}
			}                                //뿅 
		}
		if(py>1 && tick%2==0){
			py = spaceclear(px,py);
		} 
		gotoxy(x,y);
		if(kbhit() && tick%1==0){
   			SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), qcolor);
			ch = getch();
			if(ch==27){
				over();
				return 0;
			}
			else if(ch==32 && py<=1){
				py = y-1;
				px = x+j;
				space(px, py);
				Sleep(5);
				py = spaceclear(px,py);
				py --;
			}                        //space
			else if(ch==224 && tick%1==0){
				ch = getch();
					if(ch==72){
						if(y<11) continue;
						clear(x, y);
						y = up(x, y);
					}                 //up
					else if(ch==80){
						if(y>25) continue;
						clear(x, y);
						y = down(x, y);
					}                 //down
					else if(ch==77){
						if(x>63) continue;
						clear(x, y);
						x = right(x, y);
					}                 //right
					else if(ch==75){
						if(x<4) continue;
						clear(x, y);
						x = left(x,y);
					}                 //left
			} else continue;
		}
		Sleep(5);
		tick ++;
	}
}
void clear(int x, int y){      //클리어 
	printf("     ");
	gotoxy(x,y+1);
	printf("     ");
}

void mbox(int xmbox, int ymbox){     //몬스터박스  
		color(12);
		gotoxy(xmbox-1, ymbox-1);
		printf("▨▨▨"); 
		gotoxy(xmbox-1, ymbox);
		printf("▨▨▨");
		gotoxy(xmbox-1, ymbox+1);
		printf("▨▨▨");
}
int spaceclear(int px, int py){
	gotoxy(px, py);
	printf("  ");
	gotoxy(px, py-1);
	printf("  ");
	
	return py-1;
}
void space(int px, int py){    
	
	gotoxy(px, py);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("||");
	gotoxy(px, py-1);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("||"); 
}

int up(int x, int y){
	
	gotoxy(x,y-1);
	printf("  △");
	gotoxy(x,y);
	printf("◁■▷");
	
	return y-1;
}

int down(int x, int y){
	
	gotoxy(x,y+1);
	printf("  △");
	gotoxy(x,y+2);
	printf("◁■▷");
	
	return y+1;
}

int right(int x, int y){
	
	gotoxy(x+2,y);
	printf("  △");
	gotoxy(x+2,y+1);
	printf("◁■▷");
	
	return x+2; 
}

int left(int x, int y){
	
	gotoxy(x-2,y);
	printf("  △");
	gotoxy(x-2,y+1);
	printf("◁■▷");
	
	return x-2;
}

void gotoxy(int x, int y){
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void color(int a){
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), a);
}

void box(int xbox, int ybox){
	color(11);
	gotoxy(xbox, ybox);
	printf("■");
}

void over(){
	
	int i;
	
	color(12);
	gotoxy(0,0);
	printf("┌──────────────────────────────────┐\n"); //0
	for(i=0; i<28; i++) printf("│                                                                    │\n");
	printf("└──────────────────────────────────┘\n"); //28
	gotoxy(26,14);
	printf("G  A  M  E  O  V  E  R");
	gotoxy(0,30);
	Sleep(10000);
}

void mclear(int mxbox, int mybox){
	gotoxy(mxbox-1, mybox-1);
	printf("      ");
	gotoxy(mxbox-1, mybox);
	printf("      ");
	gotoxy(mxbox-1, mybox+1);
	printf("      ");
}
