#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//定义选项枚举
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
	//创建通讯录 data指针 size 及capcity容量
	struct Contact con;
	//初始化通讯录
	InitContact(&con);
	do{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			//add添加
			addData(&con);
			break;
		case DEL:
			//del删除
			deleteData(&con);
			break;
		case SEARCH:
			//search查找
			searchData(&con);
			break;
		case MODIFY:
			//modify修改
			modifyData(&con);
			break;
		case SHOW:
			//show打印
			showData(&con);
			break;
		case SORT:
			//sort排序
			sortData(&con);
			break;
		case EXIT:
			//退出时销毁通讯录
			saveData(&con);
			destroyData(&con);
			printf("退出\n");
			break;
		case SAVE:
			//文件保存个人信息
			saveData(&con);
			break;
		default:
			printf("选择错误，请确认后重新输入");
			break;
		}
	} while (input);
}
int main(){
	test();
	return 0;
}