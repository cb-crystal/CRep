#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

void menu() {
	printf("****************************\n");
	printf("*****1 play or 0 exit  *****\n");
	printf("*****��ӭ������������Ϸ ****\n");
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
			//��ӡ����
			printf(" %c ",arr[i][j]);
			if(j<col-1) printf("|");
		}
		printf("\n");
		if(i<row-1) {
			//��ӡ�ָ���
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
	printf("�����:\n");
	while(1) {
		printf("����������:>\n");
		scanf("%d%d",&x,&y);
		if(x>=1&&x<=row&&y>=1&&y<=col) {
			if(arr[x-1][y-1]==' ') {
				arr[x-1][y-1]='*';
				break;
			} else {
				printf("�����걻ռ��");
			}
		} else {
			printf("�����������\n");
		}
	}
}

void computerMove(char arr[ROW][COL],int row,int col) {
	int x=0;
	int y=0;
	printf("������\n");
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
	// * ���Ӯ #����Ӯ Q ƽ�� C ���� 
	int x=0;
	int y=0;
	//������
	for(x=0; x<row; x++) {
		if(arr[x][0]==arr[x][1]&&arr[x][1]==arr[x][2]&&arr[x][1]!=' ') {
			return arr[x][0];
		}
	}
	//������
	for(y=0; y<col; y++) {
		if(arr[0][y]==arr[1][y]&&arr[1][y]==arr[2][y]&&arr[1][y]!=' ') {
			return arr[y][0];
		}
	}
	//�Խ���
	if(arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2]&&arr[2][2]!=' '){
		return arr[0][0];
	}
	if(arr[2][0]==arr[1][1]&&arr[1][1]==arr[0][2]&&arr[1][1]!=' '){
		return arr[2][0];
	}
	//ƽ��
	if(1==isFull(arr,ROW,COL)){
		return 'Q';
	}
	//����
	return 'C';
}

void startGame() {
	char ret=0;
	char arr[ROW][COL]= {0};
	//��ʼ������Ԫ��
	InitBoard(arr,ROW,COL);
	//��ӡ����
	// ---|---|---
	// ---|---|---
	// ---|---|---
	printBoard(arr,ROW,COL);
	//����
	while(1) {
		//�����
		playerMove(arr,ROW,COL);
		printBoard(arr,ROW,COL);
		ret=isWin(arr,ROW,COL);
		if(ret!='C') {
			break;
		}

		//������
		computerMove(arr,ROW,COL);
		printBoard(arr,ROW,COL);
		ret=isWin(arr,ROW,COL);
		if(ret!='C') {
			break;
		}
	}
	if(ret=='*') {
		printf("��ϲ�㣬��Ӯ��\n"); 
	} else if(ret=='#') {
		printf("�治��,����Ӯ\n");
	} else {
		printf("ƽ��\n");
	}


}
void test() {
	int input=0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("������:>");
		scanf("%d",&input);
		switch(input) {
			case 1:
				startGame();
				break;
			case 0:
				printf("�˳���Ϸ");
				break;
			default:
				printf("��������������ȷ�Ϻ�������");
				break;
		}
	} while(input);
}
int main() {
	test();
	return 0;
}
