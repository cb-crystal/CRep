#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
#include <string.h>

//��̬��ʼ��
//void InitContact(struct Contact* pcon){
//	memset(pcon->data, 0, sizeof(pcon->data));
//	pcon->size = 0;
//}
//����Check
void CheckCapcity(struct Contact* pcon);
//��̬��ʼ��
void InitContact(struct Contact* pcon){
	pcon->data = (struct Person*)malloc(DEFAULT_SIZE*sizeof(struct Person));
	if (pcon->data == NULL){
		return;
	}
	pcon->size = 0;
	pcon->capacity = DEFAULT_SIZE;
	//�����ѱ�����ļ���Ϣ
	loadData(pcon);
}

void loadData(struct Contact* pcon){
	//��䱣������
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
	//�ر��ļ�
	fclose(pfRead);
	pfRead = NULL;
}
void CheckCapcity(struct Contact* pcon){
	if (pcon->size == pcon->capacity){
		struct Person* pstr = (struct Person*)realloc(pcon->data, (DEFAULT_SIZE + 2)*sizeof(struct Person));
		if(pstr!=NULL){
			pcon->data = pstr;
			pcon->capacity +=2;//��������2
			printf("���ݳɹ�\n");
		}
		else{
			printf("����ʧ��\n");
		}
	}
}
void addData(struct Contact* pcon){
	//��̬���� 1.��������Ƿ��� 2.û�����ռ��㹻���������
	CheckCapcity(pcon);
	printf("������Ҫ�������Ϣ������:>\n");
	scanf("%s", pcon->data[pcon->size].name);
	printf("������Ҫ�������Ϣ������:>\n");
	scanf("%d", &(pcon->data[pcon->size].age));
	printf("������Ҫ�������Ϣ���Ա�:>\n");
	scanf("%s", pcon->data[pcon->size].sex);
	printf("������Ҫ�������Ϣ�ĵ绰:>\n");
	scanf("%s", pcon->data[pcon->size].tel);
	printf("������Ҫ�������Ϣ�ĵ�ַ:>\n");
	scanf("%s", pcon->data[pcon->size].addr);
	pcon->size++;
	printf("��ӳɹ�\n");
	//��̬��������
	/*if (pcon->size > MAX){
		printf("ͨѶ¼�������޷��������");
	}
	else{
		printf("������Ҫ�������Ϣ������:>\n");
		scanf("%s", pcon->data[pcon->size].name);
		printf("������Ҫ�������Ϣ������:>\n");
		scanf("%d", &(pcon->data[pcon->size].age));
		printf("������Ҫ�������Ϣ���Ա�:>\n");
		scanf("%s", pcon->data[pcon->size].sex);
		printf("������Ҫ�������Ϣ�ĵ绰:>\n");
		scanf("%s", pcon->data[pcon->size].tel);
		printf("������Ҫ�������Ϣ�ĵ�ַ:>\n");
		scanf("%s", pcon->data[pcon->size].addr);
		pcon->size++;
		printf("��ӳɹ�\n");
	}*/
}

void showData(const struct Contact* pcon){
	if (pcon->size == 0){
		printf("ͨѶ¼Ϊ��\n");
	}
	else{
		//����
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\t\n","����","����","�Ա�","�绰","סַ");
		//��ӡ
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
	printf("����������ɾ������Ϣ������:>\n");
	scanf("%s", &name);
	//��������ɾ�����˵�����
	int pos = findName(pcon,name);
	if (pos == -1){
		printf("��ɾ�����˲�����\n");
	}
	else{
		for (int j = pos; j < pcon->size - 1; j++){
			pcon->data[j] = pcon->data[j+1];
		}
		pcon->size--;
		printf("ɾ���ɹ�\n");
	}
}
void searchData(struct Contact* pcon){
	char name[MAX_NAME] = { 0 };
	printf("�����������������Ϣ������:>\n");
	scanf("%s", &name);
	//����������ҵ��˵�����
	int pos = findName(pcon, name);
	if (pos == -1){
		printf("�����ҵ��˲�����\n");
	}
	else{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\t\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\t\n",
			pcon->data[pos].name,
			pcon->data[pos].age,
			pcon->data[pos].sex,
			pcon->data[pos].tel,
			pcon->data[pos].addr);
		printf("���ҳɹ�");
	}
}
void modifyData(struct Contact* pcon){
	char name[MAX_NAME] = { 0 };
	printf("�����������޸�����Ϣ������:>\n");
	scanf("%s", &name);
	//�����޸��˵�����
	int pos = findName(pcon, name);
	if (pos == -1){
		printf("���޸ĵ�����Ϣ������\n");
	}
	else{
		printf("����������:>\n");
		scanf("%s", pcon->data[pos].name);
		printf("����������:>\n");
		scanf("%d", &(pcon->data[pos].age));
		printf("�������Ա�:>\n");
		scanf("%s", pcon->data[pos].sex);
		printf("������绰:>\n");
		scanf("%s", pcon->data[pos].tel);
		printf("�������ַ:>\n");
		scanf("%s", pcon->data[pos].addr);
		printf("�޸ĳɹ�\n");
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
	//��ӡ
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\t\n", "����", "����", "�Ա�", "�绰", "סַ");
	for (int k = 0; k < pcon->size; k++){
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\t\n",
			pcon->data[k].name,
			pcon->data[k].age, 
			pcon->data[k].sex, 
			pcon->data[k].tel, 
			pcon->data[k].addr);
	}
	printf("����ɹ�\n");
}

//����ͨѶ¼,�ͷŶ�̬�ڴ�ռ�
void destroyData(struct Contact* pcon){
	free(pcon->data);
	pcon->data = NULL;
}

//����ͨѶ¼
void saveData(struct Contact* pcon){
	//���ļ�
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL){
		return;
	}
	for (int i = 0; i < pcon->size; i++){
		fwrite(&(pcon->data[i]), sizeof(struct Person), 1, pfWrite);
	}
	//�ر��ļ�
	fclose(pfWrite);
	pfWrite = NULL;
	printf("����ɹ�\n");
}
