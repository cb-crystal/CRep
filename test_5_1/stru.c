#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//����һ���ṹ������
//����һ��ѧ�����ͣ���ͨ��ѧ�����ʹ���ѧ��������ÿһ��ѧ������һ������
//ѧ�����߱�����:����+����+�绰+�Ա�
//struct Stu{
//	char name[20];//����
//	int age;//����
//	char phone[20];//�绰
//	char sex[10];//�Ա�
//}s3, s4, s5;
////s3~s6��Ϊ�ṹ��ȫ�ֱ���
//struct Stu s6;
//int main(){
//	//ͨ��ѧ�����ʹ���ѧ������(����s1��s2 Ϊ�ṹ��ֲ�����)����ʼ��������ֵ��
//	struct Stu s1 = { "����", 18, "15884576252", "��" };
//	struct Stu s2 = { "��С��", 18, "15884767252", "Ů" };
//	return 0;
//}

//ͨ�������жϵ�ǰ��С���ֽ���
int check_sys(){
	union un
	{
		char c;
		int i;
	}u;
	u.i = 1;
	return u.c;
}
int main(){
	int ret = check_sys();
	if (1 == ret){
		printf("С��\n");
	}
	else{
		printf("���\n");
	}
	return 0;
}