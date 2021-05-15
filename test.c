#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//����ѡ��ö��
enum Option{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE
};
void menu(){
	printf("***************************\n");
	printf("******1.add    2.del ******\n");
	printf("******3.sea    4.mod ******\n");
	printf("******5.sho    6.sor ******\n");
	printf("******7.save   0.exit******\n");
	printf("***************************\n");
}
void test(){
	int input = 0;
	//����ͨѶ¼ dataָ�� size ��capcity����
	struct Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			//add���
			addData(&con);
			break;
		case DEL:
			//delɾ��
			deleteData(&con);
			break;
		case SEARCH:
			//search����
			searchData(&con);
			break;
		case MODIFY:
			//modify�޸�
			modifyData(&con);
			break;
		case SHOW:
			//show��ӡ
			showData(&con);
			break;
		case SORT:
			//sort����
			sortData(&con);
			break;
		case EXIT:
			//�˳�ʱ����ͨѶ¼
			saveData(&con);
			destroyData(&con);
			printf("�˳�\n");
			break;
		case SAVE:
			//�ļ����������Ϣ
			saveData(&con);
			break;
		default:
			printf("ѡ�������ȷ�Ϻ���������");
			break;
		}
	} while (input);
}
int main(){
	test();
	return 0;
}