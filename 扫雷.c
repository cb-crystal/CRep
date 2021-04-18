#define ROW 9
#define COL 9
#define ROWS  ROW+2
#define COLS  COL+2
#define EASY_COUNT 80
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu() {
	printf("/******* 欢迎扫雷*******/\n");
	printf("/*****1 play 0 exit*****/\n");
	printf("/***********************/\n");
}
void InitData(char mine[ROWS][COLS],int row,int col,char ret) {

	int x=0;
	int y=0;
	for(x=0; x<row; x++) {
		for(y=0; y<col; y++) {
			mine[x][y]=ret;
		}
	}
}

void printShow(char show[ROWS][COLS],int row,int col) {
	int x=0;
	int y=0;
	int x2=0;
	for(x=0; x<=col; x++) {
		printf(" %d ",x);
	}
	printf("\n");
	for(x=1; x<=row; x++) {
		printf(" %d ",x);
		for(y=1; y<=col; y++) {
			printf(" %c ",show[x][y]);
		}
		printf("\n");
	}
}

void printMine(char mine[ROWS][COLS],int row,int col) {
	int x=0;
	int y=0;

	for(x=0; x<=col; x++) {
		printf(" %d ",x);
	}
	printf("\n");
	for(x=1; x<=row; x++) {
		printf(" %d ",x);
		for(y=1; y<=col; y++) {
			printf(" %c ",mine[x][y]);
		}
		printf("\n");
	}
}
void setMine(char mine[ROWS][COLS],int row,int col) {
	//9*9-10
	int count=EASY_COUNT;
	while(count) {
		//%row 0~8 1~9 %row=row+1
		int x=rand()%row+1;
		int y=rand()%col+1;
		if(mine[x][y]=='0') {
			mine[x][y]='1';
			count--;
		}
	}
}
int get_mine_count(char mine[ROWS][COLS],int x,int y) {
	return mine[x][y-1]+
	       mine[x][y+1]+
	       mine[x-1][y-1]+
	       mine[x-1][y+1]+
	       mine[x+1][y]+
	       mine[x-1][y]+
	       mine[x+1][y+1]+
	       mine[x+1][y-1]-8*'0';
}
void findMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col) {
	int x=0;
	int y=0;
	int num=0;
	printMine(mine,ROW,COL);
	while(num<row*col-EASY_COUNT) {
		printf("请输入坐标>:");
		scanf("%d%d",&x,&y);
		if(mine[x][y]=='1') {
			printf("很遗憾，你被炸死了\n");
			printMine(mine,ROW,COL);
			break;
		} else {
			//没被炸
			int count=get_mine_count(mine,x,y);
			printMine(mine,ROW,COL);
			show[x][y]=count+'0';
			printShow(show,ROW,COL);
			num++;
		}
	}
	if(num==row*col-EASY_COUNT) {
		printf("恭喜你，扫雷成功\n");
	}
}
void startGame() {
	//存放雷的数组
	char mine[ROWS][COLS]= {0};
	//存放排雷信息的数组
	char show[ROWS][COLS]= {0};
	//初始化俩个数组数据

	InitData(mine,ROWS,COLS,'0');
	InitData(show,ROWS,COLS,'*');
	//打印棋盘
	printShow(show,ROW,COL);
	printMine(mine,ROW,COL);
//	设置炸弹
	setMine(mine,ROW,COL);
//	printMine(mine,ROW,COL);
	//排雷
	findMine(mine,show,ROW,COL);
}
void test() {
	int input=0;
	srand((unsigned int)time(NULL));

	do {
		menu();
		printf("请输入>:");
		scanf("%d",&input);
		switch(input) {
			case 1:
				startGame();
				break;
			case 0:
				printf("退出游戏");
				break;
			default:
				printf("输入错误，请重新输入");
				break;
		}
	} while(input);
}
int main() {
	test();
	return 0;
}
