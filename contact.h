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

//����������Ϣ
struct Person{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tel[MAX_TEL];
	char addr[MAX_ADDR];
};

//ͨѶ¼
struct Contact
{
	int size;
	/*struct Person data[MAX];*/ //��̬�ڴ�
	struct Person* data; //�ṹ�嶯̬�ڴ�ָ��->��ǰ�ṹ������ж��ٸ�
	int capacity; //�ṹ�嶯ָ̬�뵱ǰ������
};
//��ʼ��ͨѶ¼
void InitContact(struct Contact* pcon);
//���ͨѶ¼����
void addData(struct Contact* pcon);
//�鿴ͨѶ¼����
void showData(const struct Contact* pcon);
//ɾ��ͨѶ¼��ָ��������Ϣ����
void deleteData(struct Contact* pcon);
//����ͨѶ¼��ָ��������Ϣ����
void searchData(struct Contact* pcon);
//�޸�ͨѶ¼��ָ���˵���Ϣ����
void modifyData(struct Contact* pcon);
//�����ֽ�����ʾ
void sortData(struct Contact* pcon);
//����ͨѶ¼
void destroyData(struct Contact* pcon);
//����ͨѶ¼��Ϣ
void saveData(struct Contact* pcon);
//�����ѱ�����ļ���Ϣ
void loadData(struct Contact* pcon);