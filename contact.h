#define _CRT_SECURE_NO_WARNINGS 1

//#define MAX 1000
#define MAX_NAME  20
#define MAX_SEX  5
#define MAX_TEL 12
#define MAX_ADDR 20
#define DEFAULT_SIZE 3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//创建个人信息
struct Person{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char addr[MAX_ADDR];
};

//通讯录
struct Contact
{
	int size;
	/*struct Person data[MAX];*/ //静态内存
	struct Person* data; //结构体动态内存指针->当前结构体变量有多少个
	int capacity; //结构体动态指针当前的容量
};
//初始化通讯录
void InitContact(struct Contact* pcon);
//添加通讯录数据
void addData(struct Contact* pcon);
//查看通讯录数据
void showData(const struct Contact* pcon);
//删除通讯录中指定的人信息数据
void deleteData(struct Contact* pcon);
//查找通讯录中指定的人信息数据
void searchData(struct Contact* pcon);
//修改通讯录中指定人的信息数据
void modifyData(struct Contact* pcon);
//以名字降序显示
void sortData(struct Contact* pcon);
//销毁通讯录
void destroyData(struct Contact* pcon);
//保存通讯录信息
void saveData(struct Contact* pcon);
//加载已保存的文件信息
void loadData(struct Contact* pcon);