#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
#include <string.h>

//静态初始化
//void InitContact(struct Contact* pcon){
//	memset(pcon->data, 0, sizeof(pcon->data));
//	pcon->size = 0;
//}
//声明Check
void CheckCapcity(struct Contact* pcon);
//动态初始化
void InitContact(struct Contact* pcon){
	pcon->data = (struct Person*)malloc(DEFAULT_SIZE*sizeof(struct Person));
	if (pcon->data == NULL){
		return;
	}
	pcon->size = 0;
	pcon->capacity = DEFAULT_SIZE;
	//加载已保存的文件信息
	loadData(pcon);
}

void loadData(struct Contact* pcon){
	//填充保存数据
	FILE* pfRead = fopen("contact.dat", "rb");
	struct Person temp = { 0 };
	if (pfRead == NULL){
		return;
	}
	while (fread(&temp, sizeof(struct Person), 1, pfRead)){
		CheckCapcity(pcon);
		pcon->data[pcon->size] = temp;
		pcon->size++;
	}
	//关闭文件
	fclose(pfRead);
	pfRead = NULL;
}
void CheckCapcity(struct Contact* pcon){
	if (pcon->size == pcon->capacity){
		struct Person* pstr = (struct Person*)realloc(pcon->data, (DEFAULT_SIZE + 2)*sizeof(struct Person));
		if(pstr!=NULL){
			pcon->data = pstr;
			pcon->capacity +=2;//容量增加2
			printf("增容成功\n");
		}
		else{
			printf("增容失败\n");
		}
	}
}
void addData(struct Contact* pcon){
	//动态扩容 1.检查容量是否满 2.没满，空间足够则添加数据
	CheckCapcity(pcon);
	printf("请输入要添加人信息的姓名:>\n");
	scanf("%s", pcon->data[pcon->size].name);
	printf("请输入要添加人信息的年龄:>\n");
	scanf("%d", &(pcon->data[pcon->size].age));
	printf("请输入要添加人信息的性别:>\n");
	scanf("%s", pcon->data[pcon->size].sex);
	printf("请输入要添加人信息的电话:>\n");
	scanf("%s", pcon->data[pcon->size].tel);
	printf("请输入要添加人信息的地址:>\n");
	scanf("%s", pcon->data[pcon->size].addr);
	pcon->size++;
	printf("添加成功\n");
	//静态增加数据
	/*if (pcon->size > MAX){
		printf("通讯录已满，无法添加数据");
	}
	else{
		printf("请输入要添加人信息的姓名:>\n");
		scanf("%s", pcon->data[pcon->size].name);
		printf("请输入要添加人信息的年龄:>\n");
		scanf("%d", &(pcon->data[pcon->size].age));
		printf("请输入要添加人信息的性别:>\n");
		scanf("%s", pcon->data[pcon->size].sex);
		printf("请输入要添加人信息的电话:>\n");
		scanf("%s", pcon->data[pcon->size].tel);
		printf("请输入要添加人信息的地址:>\n");
		scanf("%s", pcon->data[pcon->size].addr);
		pcon->size++;
		printf("添加成功\n");
	}*/
}

void showData(const struct Contact* pcon){
	if (pcon->size == 0){
		printf("通讯录为空\n");
	}
	else{
		//标题
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\t\n","姓名","年龄","性别","电话","住址");
		//打印
		for (int i = 0; i < pcon->size;i++){
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\t\n",
				pcon->data[i].name,
				pcon->data[i].age, 
				pcon->data[i].sex, 
				pcon->data[i].tel, 
				pcon->data[i].addr);
		}
	}
}
int findName(struct Contact* pcon, char* pname){
	for (int i = 0; i < pcon->size; i++){
		if (0 == strcmp(pcon->data[i].name, pname)){
			return i;
		}
	}
	return -1;
}

void deleteData(struct Contact* pcon){
	char name[MAX_NAME] = { 0 };
	printf("请输入所需删除人信息的名字:>\n");
	scanf("%s", &name);
	//查找所需删除的人的姓名
	int pos = findName(pcon,name);
	if (pos == -1){
		printf("所删除的人不存在\n");
	}
	else{
		for (int j = pos; j < pcon->size - 1; j++){
			pcon->data[j] = pcon->data[j+1];
		}
		pcon->size--;
		printf("删除成功\n");
	}
}
void searchData(struct Contact* pcon){
	char name[MAX_NAME] = { 0 };
	printf("请输入所需查找人信息的名字:>\n");
	scanf("%s", &name);
	//查找所需查找的人的姓名
	int pos = findName(pcon, name);
	if (pos == -1){
		printf("所查找的人不存在\n");
	}
	else{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\t\n", "姓名", "年龄", "性别", "电话", "住址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\t\n",
			pcon->data[pos].name,
			pcon->data[pos].age,
			pcon->data[pos].sex,
			pcon->data[pos].tel,
			pcon->data[pos].addr);
		printf("查找成功");
	}
}
void modifyData(struct Contact* pcon){
	char name[MAX_NAME] = { 0 };
	printf("请输入所需修改人信息的名字:>\n");
	scanf("%s", &name);
	//查找修改人的名字
	int pos = findName(pcon, name);
	if (pos == -1){
		printf("所修改的人信息不存在\n");
	}
	else{
		printf("请输入姓名:>\n");
		scanf("%s", pcon->data[pos].name);
		printf("请输入年龄:>\n");
		scanf("%d", &(pcon->data[pos].age));
		printf("请输入性别:>\n");
		scanf("%s", pcon->data[pos].sex);
		printf("请输入电话:>\n");
		scanf("%s", pcon->data[pos].tel);
		printf("请输入地址:>\n");
		scanf("%s", pcon->data[pos].addr);
		printf("修改成功\n");
	}
}
void sortData(struct Contact* pcon){
	for (int i = 0; i < pcon->size; i++){
		for (int j = 0; j < pcon->size - 1 - i; j++){
			if (strcmp(pcon->data[j].name, pcon->data[j + 1].name) < 0){
				struct Person temp = pcon->data[j];
				pcon->data[j] = pcon->data[j + 1];
				pcon->data[j + 1] = temp;
			}
		}
	}
	//打印
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\t\n", "姓名", "年龄", "性别", "电话", "住址");
	for (int k = 0; k < pcon->size; k++){
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\t\n",
			pcon->data[k].name,
			pcon->data[k].age, 
			pcon->data[k].sex, 
			pcon->data[k].tel, 
			pcon->data[k].addr);
	}
	printf("排序成功\n");
}

//销毁通讯录,释放动态内存空间
void destroyData(struct Contact* pcon){
	free(pcon->data);
	pcon->data = NULL;
}

//保存通讯录
void saveData(struct Contact* pcon){
	//打开文件
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL){
		return;
	}
	for (int i = 0; i < pcon->size; i++){
		fwrite(&(pcon->data[i]), sizeof(struct Person), 1, pfWrite);
	}
	//关闭文件
	fclose(pfWrite);
	pfWrite = NULL;
	printf("保存成功\n");
}
