#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include <conio.h>
#include <time.h>

#define MOVE 1
#define SETTIME 30 

void over();                                          //���ӿ���  
void laser(int x, int y);                           //������ 
void score_put(int score);							// ���� 
void goalbox(int goal_x, int goal_y); 			//�������� 
void box(int box_x, int box_y);					// �ڽ� 
void color(int a);                      	//��»��� 
void clear(int x, int y);					//�������ڸ� ����� 
void gotoxy(int x, int y);             		//��ǥ�ΰ����Լ�
void mapping(int n);						// ���� 
void move(int box_x, int box_y);			// �ڽ� �ű�� 
int side(int n, int x, int y);				// �翷�̵� 
int updown(int n, int x, int y);			// ���Ʒ��̵� 

int main(void){
	
	float timer=30;                // 
	int push=0, pushw=0;         //�ڽ����ж� ����ī��Ʈ + ���� 
	int laser_x=32, laser_y=10;          // ������(?) 
	int score=0;                //���� 
	int goal_x=50, goal_y=21; 	//���� 
	int box_x=50, box_y=20;  	 	//�ڽ� 
	int x=82, y=20;				// ĳ���� ��ǥ 
	int test = 1;    	   // �׽�Ʈ�� ���� 
	int tick=0;     		 //ƽ 
	int ch;      			  // Ű���� �Է°� 
	int sic=0; 				//������� �ð� ���� 
	int on=1;               // ���� ����ִ��� Ȯ�� 
	int i, j;
	int level=1 ;
	
	gotoxy(70,20);
	printf("P R E S S   A N Y T H I N G ");
    
    //  30,5  132,5
	//  30,37 132,37
	// ���� �׵θ����� Ư�������� 50 ������� 100
	// ���� �׵θ����� 30
				
	while(1){
		if(kbhit()){
			system("cls");
			mapping(30);
			gotoxy(x, y);
			color(8);
			printf("��");
			break;
		}
	}
	
   	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 15); // ���������� 
	gotoxy(0,0);
   	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0); 
	
	srand(time(NULL));
	score_put(score);
	
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo); // Ŀ�� ������ 
	
	gotoxy(149, 16);
	printf("%.2f  ", timer);
	
	while(1){
		if(tick%1 == 0){
			timer -= 0.01;
			gotoxy(149, 16);
			color(10);
			if(timer <= 10) color(14);
			if(timer <= 5) color(12);
			printf("%.2f  ", timer);
		}
		if(timer <= 0) over();
		if(tick%1==0 && box_x == goal_x && box_y == goal_y){
			on = 1;
			score ++;
			timer = SETTIME - level++;
			score_put(score);
		}						//���� 
		if(tick%27 == 0 && push == 1){
			if(pushw == 1){
				if(box_y == laser_y+1 && box_x <= laser_x){
					push = 0;
					continue;
				}
				if(box_y<7){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box(box_x, --box_y);
			}else if(pushw == 2){
				if(box_y == laser_y-1 && box_x <= laser_x){
					push = 0;
					continue;
				}
				if(box_y>35){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box(box_x, ++box_y);
			}else if(pushw == 3){
				if(box_x>128){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box_x += 2;
				box(box_x, box_y);
			}else{
				if(box_y == laser_y) laser_x -= 2;
				if(box_x<34){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box_x -= 2;
				box(box_x, box_y);
			}
			push --;
		}else if(tick%20 == 0 && push == 2){
			if(pushw == 1){
				if(box_y == laser_y+1 && box_x <= laser_x){
					push = 0;
					continue;
				}
				if(box_y<7){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box(box_x, --box_y);
			}else if(pushw == 2){
				if(box_y == laser_y-1 && box_x <= laser_x){
					push = 0;
					continue;
				}
				if(box_y>35){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box(box_x, ++box_y);
			}else if(pushw == 3){
				if(box_x>128){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box_x += 2;
				box(box_x, box_y);
			}else{
				if(box_y == laser_y) laser_x -= 2;
				if(box_x<34){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box_x -= 2;
				box(box_x, box_y);
			}
			push --;
		}else if(tick%13 == 0 && push == 3){
			if(pushw == 1){
				if(box_y == laser_y+1 && box_x <= laser_x){
					push = 0;
					continue;
				}
				if(box_y<7){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box(box_x, --box_y);
			}else if(pushw == 2){
				if(box_y == laser_y-1 && box_x <= laser_x){
					push = 0;
					continue;
				}
				if(box_y>35){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box(box_x, ++box_y);
			}else if(pushw == 3){
				if(box_x>128){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box_x += 2;
				box(box_x, box_y);
			}else{
				if(box_y == laser_y) laser_x -= 2;
				if(box_x<34){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box_x -= 2;
				box(box_x, box_y);
			}
			push --;
		}else if(tick%8 == 0 && push == 4){
			if(pushw == 1){
				if(box_y == laser_y+1 && box_x <= laser_x){
					push = 0;
					continue;
				}
				if(box_y<7){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box(box_x, --box_y);
			}else if(pushw == 2){
				if(box_y == laser_y-1 && box_x <= laser_x){
					push = 0;
					continue;
				}
				if(box_y>35){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box(box_x, ++box_y);
			}else if(pushw == 3){
				if(box_x>128){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box_x += 2;
				box(box_x, box_y);
			}else{
				if(box_y == laser_y) laser_x -= 2;
				if(box_x<34){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box_x -= 2;
				box(box_x, box_y);
			}
			push --;
		}else if(tick%5 == 0 && push == 5){
			if(pushw == 1){
				if(box_y == laser_y+1 && box_x <= laser_x){
					push = 0;
					continue;
				}
				if(box_y<7){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box(box_x, --box_y);
			}else if(pushw == 2){
				if(box_y == laser_y-1 && box_x <= laser_x){
					push = 0;
					continue;
				}
				if(box_y>35){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box(box_x, ++box_y);
			}else if(pushw == 3){
				if(box_x>128){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box_x += 2;
				box(box_x, box_y);
			}else{
				if(box_y == laser_y) laser_x -= 2;
				if(box_x<34){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box_x -= 2;
				box(box_x, box_y);
			}
			push --;
		}else if(tick%3 == 0 && push == 6){
			if(pushw == 1){
				if(box_y == laser_y+1 && box_x <= laser_x){
					push = 0;
					continue;
				}
				if(box_y<7){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box(box_x, --box_y);
			}else if(pushw == 2){
				if(box_y == laser_y-1 && box_x <= laser_x){
					push = 0;
					continue;
				}
				if(box_y>35){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box(box_x, ++box_y);
			}else if(pushw == 3){
				if(box_x>128){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box_x += 2;
				box(box_x, box_y);
			}else{
				if(box_y == laser_y) laser_x -= 2;
				if(box_x<34){
					push = 0;
					continue;
				}
				clear(box_x, box_y);
				box_x -= 2;
				box(box_x, box_y);
			}
			push --;
		}
		if(x == laser_x && y == laser_y) over();
		if(on){
			clear(box_x, box_y);
			box_x = rand()%94/2*2 + 36;
			box_y = rand()%26 + 8;
			box(box_x, box_y);
			clear(goal_x, goal_y);
			goal_x = rand()%94/2*2 + 36;
			goal_y = rand()%26 + 8;
			if(goal_y == laser_y) goal_y = 15;
			goalbox(goal_x, goal_y);
			on = 0;
		}						//�ڽ� 
		if(laser_x==32){
			laser_y = rand()%26 + 8;
			if(laser_y == goal_y) continue; 
		}
		if(tick%300==0 && laser_x==132){
			if(j==130) laser_x = 32;
			clear(j, laser_y);
			j+=2;
			continue;
		}
		if(tick%20==0 && laser_x <= 131){
			if(laser_x==box_x && laser_y==box_y) laser_x-=2;
			if(laser_x==goal_x && laser_y==goal_y) laser_x=goal_x+2;
			laser(laser_x, laser_y);
			laser_x += 2;
			j=32;
		}
		if(tick%500==0) sic = 1;
		if(kbhit()){
			ch = getch();
			if(ch == 32){
				if(box_x == x && box_y+1 == y){
					if(box_y == laser_y+1 && box_x <= laser_x) continue;
					if(box_y<7) continue;
					clear(box_x, box_y);
					box(box_x, --box_y);
					push = 4; 
					pushw = 1;
				}else if(box_x == x && box_y-1 == y){
					if(box_y == laser_y-1 && box_x <= laser_x) continue;
					if(box_y>35) continue;
					clear(box_x, box_y);
					box(box_x, ++box_y);
					push = 4; 
					pushw = 2;
				}else if(box_x-2 == x && box_y == y){
					if(box_x>128) continue;
					box(box_x+2, box_y);
					clear(box_x, box_y);
					box_x += 2;
					push = 4;
					pushw = 3; 
				}else if(box_x+2 == x && box_y == y){
					if(box_x<34) continue;
					if(box_y == laser_y) laser_x -= 4;
					box(box_x-2, box_y);
					clear(box_x, box_y);
					box_x -= 2;
					push = 6; 
					pushw = 4;
				}                   // �ڽ� Ǫ�� 
			}
			if(ch == 114 && sic == 1 ){
				sic=0;
				on=1;
			}								//�ڽ� ����� 
			if(ch == 224){                   //����Ű 
				ch = getch();if(ch == 72){
					if(y<7) continue;
					if(y-1 == laser_y && x < laser_x) continue;
					if(x == goal_x && y-1 == goal_y) continue;
					if(box_x == x && box_y+1 == y){
						if(box_y == laser_y+1 && box_x <= laser_x) continue;
						if(box_y<7) continue;
						box(box_x, --box_y);
					}
					clear(x, y);
					y = updown(-MOVE, x, y);
				}                 //up
				else if(ch == 80){
					if(y>35) continue;
					if(y+1 == laser_y && x < laser_x) continue;
					if(x == goal_x && y+1 == goal_y) continue;
					if(box_x == x && box_y-1 == y){
						if(box_y == laser_y-1 && box_x <= laser_x) continue;
						if(box_y>35) continue;
						box(box_x, ++box_y);
					}
					clear(x, y);
					y = updown(MOVE, x, y);
				}                 //down
				else if(ch == 77){
					if(x>128) continue;
					if(x+2 == goal_x && y == goal_y) continue;
					if(box_x-2 == x && box_y == y){
						if(box_x>128) continue;
						box(box_x+2, box_y);
						box_x += 2;
					}
					clear(x, y);
					x = side(MOVE, x, y);
				}                 //right
				else if(ch == 75){
					if(x<34) continue;
					if(x-2 == goal_x && y == goal_y) continue;
					if(box_x+2 == x && box_y == y){
						if(box_x<34) continue;
						box(box_x-2, box_y);
						box_x -= 2;
						if(box_y == laser_y) laser_x -= 2;
					}
					clear(x, y);
					x = side(-MOVE, x, y);
				}                 //left
			}
		}
		Sleep(5);    //  5/1000 �� 
		tick ++;
		
		//��ǥã�� ��� 
		/*
		gotoxy(60,40);
		printf("%d %d  ", x, y);
		if(kbhit()){
			ch = getch();
			if(ch == 224){                   //����Ű 
				ch = getch();
				color(12);
				if(ch==72){
					clear(x, y);
					y = updown(-MOVE, x, y);
				}                 //up
				else if(ch==80){
					clear(x, y);
					y = updown(MOVE, x, y);
				}                 //down
				else if(ch==77){
					clear(x, y);
					x = side(MOVE, x, y);
				}                 //right
				else if(ch==75){
					clear(x, y);
					x = side(-MOVE, x, y);
				}                 //left
			}               
		} */                         
	}
}
void over(){
	
	int ch;
	
	color(12);
	gotoxy(75, 3);
	printf("G A M E O V E R");
	gotoxy(0, 0);
	while(1){
		if(kbhit()){
			ch == getch();
			if(ch == 114){
				main();
			}
		}
	}
}

void laser(int x, int y){
	
	color(0);
	color(240); 
	gotoxy(x, y);
	printf("��");
}

void score_put(int score){
	
	char *sco[11]={
	"����������������������������\n",
	"��                        ��\n",
	"��        S C O R E       ��\n",
	"��                        ��\n",
	"��                        ��\n",
	"��                        ��\n",
	"��         T I M E        ��\n",
	"��                        ��\n",
	"��                        ��\n",
	"��                        ��\n",
	"����������������������������\n",
	};
	for(int i=0; i<11; i++){
		color(15);
		gotoxy(137,8+i);
		printf("%s", sco[i]);
	}
	color(10);
	gotoxy(151, 12);
	printf("%d ", score);
}
void goalbox(int goal_x, int goal_y){
	
	
	gotoxy(goal_x, goal_y);
	color(13);
	printf("��");
}

int side(int n, int x, int y){
	
	gotoxy(x+n*2,y);
	color(11);
	printf("��");
	return x+n*2;
}

int updown(int n, int x, int y){
	
	gotoxy(x,y+n);
	color(11);
	printf("��"); 
	return y+n;
}

void box(int box_x, int box_y){
	
	gotoxy(box_x, box_y);
	color(13);
	printf("��");
}

void color(int a){
	
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), a);
}

void clear(int x, int y){
	
   	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 240);
	gotoxy(x,y);
	printf("  ");
}

void gotoxy(int x, int y){
	
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void mapping(int n){
	
	char *map[] = {
				"�����������������������������������������������������\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"��                                                                                                    ��\n",
				"�����������������������������������������������������\n"
			};
	
	color(240);
	for (int i = 0; i < 33; i++) {
		gotoxy(n,i+5);
		printf("%s", map[i]);
	}
}
