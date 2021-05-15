#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//声明一个结构体类型
//声明一个学生类型，并通过学生类型创建学生变量（每一个学生都是一个对象）
//学生所具备属性:名字+年龄+电话+性别
//struct Stu{
//	char name[20];//名字
//	int age;//年龄
//	char phone[20];//电话
//	char sex[10];//性别
//}s3, s4, s5;
////s3~s6都为结构体全局变量
//struct Stu s6;
//int main(){
//	//通过学生类型创建学生变量(这里s1，s2 为结构体局部变量)并初始化（即赋值）
//	struct Stu s1 = { "张三", 18, "15884576252", "男" };
//	struct Stu s2 = { "张小丽", 18, "15884767252", "女" };
//	return 0;
//}

//通过联合判断当前大小端字节序
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
		printf("小端\n");
	}
	else{
		printf("大端\n");
	}
	return 0;
}