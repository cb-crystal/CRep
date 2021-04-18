#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

void menu() {
	printf("****************************\n");
	printf("*****1 play or 0 exit  *****\n");
	printf("*****欢迎来到三子棋游戏 ****\n");
}

void InitBoard(char arr[ROW][COL],int row,int col) {
	int i=0;
	for(i=0; i<row; i++) {
		int j=0;
		for(j=0; j<col; j++) {
			arr[i][j]=' ';
		}
	}
}


void printBoard(char arr[ROW][COL],int row,int col) {
	int i=0;
	for(i=0; i<row; i++) {
		int j=0;
		for(j=0; j<col; j++) {
			//打印数据
			printf(" %c ",arr[i][j]);
			if(j<col-1) printf("|");
		}
		printf("\n");
		if(i<row-1) {
			//打印分割行
			for(j=0; j<col; j++) {
				printf("---");

				if(j<col-1)	printf("|");
			}
			printf("\n");
		}
	}
}
void playerMove(char arr[ROW][COL],int row,int col) {
	int x=0;
	int y=0;
	printf("玩家下:\n");
	while(1) {
		printf("请输入坐标:>\n");
		scanf("%d%d",&x,&y);
		if(x>=1&&x<=row&&y>=1&&y<=col) {
			if(arr[x-1][y-1]==' ') {
				arr[x-1][y-1]='*';
				break;
			} else {
				printf("该坐标被占用");
			}
		} else {
			printf("坐标输入错误\n");
		}
	}
}

void computerMove(char arr[ROW][COL],int row,int col) {
	int x=0;
	int y=0;
	printf("电脑下\n");
	while(1) {
		x=rand()%row;
		y=rand()%col;
		if(arr[x][y]==' ') {
			arr[x][y]='#';
			break;
		}
	}
}

int isFull(char arr[ROW][COL],int row,int col){
	int x=0;
	int y=0;
	for(x=0;x<row;x++){
		for(y=0;y<col;y++){
			if(arr[x][y]==' '){
				return 0;
			}
		}
	}
	return 1;
}

char isWin(char arr[ROW][COL],int row,int col) {
	// * 玩家赢 #电脑赢 Q 平局 C 继续 
	int x=0;
	int y=0;
	//行三个
	for(x=0; x<row; x++) {
		if(arr[x][0]==arr[x][1]&&arr[x][1]==arr[x][2]&&arr[x][1]!=' ') {
			return arr[x][0];
		}
	}
	//列三个
	for(y=0; y<col; y++) {
		if(arr[0][y]==arr[1][y]&&arr[1][y]==arr[2][y]&&arr[1][y]!=' ') {
			return arr[y][0];
		}
	}
	//对角线
	if(arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2]&&arr[2][2]!=' '){
		return arr[0][0];
	}
	if(arr[2][0]==arr[1][1]&&arr[1][1]==arr[0][2]&&arr[1][1]!=' '){
		return arr[2][0];
	}
	//平局
	if(1==isFull(arr,ROW,COL)){
		return 'Q';
	}
	//继续
	return 'C';
}

void startGame() {
	char ret=0;
	char arr[ROW][COL]= {0};
	//初始化数组元素
	InitBoard(arr,ROW,COL);
	//打印键盘
	// ---|---|---
	// ---|---|---
	// ---|---|---
	printBoard(arr,ROW,COL);
	//下棋
	while(1) {
		//玩家下
		playerMove(arr,ROW,COL);
		printBoard(arr,ROW,COL);
		ret=isWin(arr,ROW,COL);
		if(ret!='C') {
			break;
		}

		//电脑下
		computerMove(arr,ROW,COL);
		printBoard(arr,ROW,COL);
		ret=isWin(arr,ROW,COL);
		if(ret!='C') {
			break;
		}
	}
	if(ret=='*') {
		printf("恭喜你，你赢了\n"); 
	} else if(ret=='#') {
		printf("真不幸,电脑赢\n");
	} else {
		printf("平局\n");
	}


}
void test() {
	int input=0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请输入:>");
		scanf("%d",&input);
		switch(input) {
			case 1:
				startGame();
				break;
			case 0:
				printf("退出游戏");
				break;
			default:
				printf("输入有误，请重新确认后再输入");
				break;
		}
	} while(input);
}
int main() {
	test();
	return 0;
}
