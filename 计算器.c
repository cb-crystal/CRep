#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//计算器
//void menu() {
//	printf("************** 计算器 ****************\n");
//	printf("******** 1 加 2 减 3 乘 4 除 *********\n");
//	printf("************** 0 退出 ******************\n");
//}
//int Add(int x,int y) {
//	return x+y;
//}
//
//int jian(int x,int y) {
//	return x-y;
//}
//
//int Mul(int x,int y) {
//	return x*y;
//}
//
//int chu(int x,int y) {
//	return x/y;
//}
//
//int yu(int x,int y) {
//	return x&y;
//}
//void test() {
//	int input=0;
//	int x=0;
//	int y=0;
//	do {
//		menu();
//		printf("请输入所需计算类型:>");
//		scanf("%d",&input);
//		int (*FArray[6])(int,int)= {0,Add,jian,Mul,chu,yu};
//		if(input>=1&&input<=5) {
//			printf("请输入所需计算的俩个数值:>");
//			scanf("%d%d",&x,&y);
//			int ret=FArray[input](x,y);
//			printf("计算后的值为:%d\n",ret);
//		} else if(input==0) {
//			printf("退出\n");
//		} else {
//			printf("输入计算类型错误，请确认后输入\n");
//		}
//	} while(input);
//}
//int main() {
//	test();
//	return 0;
//}



//结构体排序
//方法一
//结构体类型
//struct Stu {
//	char name[20];
//	int age;
//};

//进行冒泡排序
//void MaoPao(struct Stu *p,int sz,int flag) {
//	int i=0;
//	int j=0;
//
////flag=0时为姓名长度排序 1时为年龄大小排序
//	if(flag==0) {
//		for(i=0; i<sz; i++) {
//			for(j=0; j<sz-i-1; j++) {
//				if(strlen(p->name)<strlen((p+1)->name)) {
//					struct Stu t;
//					t=*p;
//					*p=*(p+1);
//					*(p+1)=t;
//				}
//				p++;
//			}
//		}
//	} else {
//		for(i=0; i<sz; i++) {
//			for(j=0; j<sz-i-1; j++) {
//				if(p->age<(p+1)->age) {
//					struct Stu t;
//					t=*p;
//					*p=*(p+1);
//					*(p+1)=t;
//				}
//				p++;
//			}
//		}
//	}
//}
//int main() {
//	//初始化结构体变量
//	struct Stu s[3]= {{"ccccccc",19},{"aaaaaaaaa",10},{"bbdb",18}};
//	struct Stu *p=s;
//	struct Stu *p2=s;
//	int i=0;
//	int sz=sizeof(s)/sizeof(s[0]);
//
////0为字符串排序，1为年龄排序
//	MaoPao(p,sz,0);
//	printf("将姓名长度从大到小输出\n");
//	for(i=0; i<sz; i++) {
//		printf("姓名:%s 年龄:%d\n",p->name,p->age);
//		p++;
//	}
//	printf("\n");
//
//
//	MaoPao(p2,sz,1);
//	printf("将年龄从大到小输出\n");
//	for(i=0; i<sz; i++) {
//		printf("姓名:%s 年龄:%d\n",p2->name,p2->age);
//		p2++;
//	}
//	return 0;
//}

//方法二

struct Stu {
	char name[20];
	int age;
};
//比较年龄
int cmp_stu_age(const void* e1,const void* e2) {
	return ((struct Stu*)e1)->age-((struct Stu*)e2)->age;
}

void test_age() {
	struct Stu s[4]= {{"aaaaaaa",18},{"bbbb",15},{"ccccccccccc",20},{"ddddd",16}};
	int sz=sizeof(s)/sizeof(s[0]);
	qsort(s,sz,sizeof(s[0]),cmp_stu_age);

	int i=0;
	struct Stu *p=s;
	for(i=0; i<sz; i++) {
		printf("%d\n",p->age);
		p++;
	}
}
//比较姓名 
int cmp_stu_name(const void* e1,const void* e2) {
//	return strlen(((struct Stu*)e1)->name)-strlen(((struct Stu*)e2)->name);
//俩个字符串比较用strcmp函数 
    return strcmp(((struct Stu*)e1)->name,((struct Stu*)e2)->name);
}
void test_name() {
	struct Stu s[4]= {{"aaaaaaa",18},{"bbbb",15},{"ccccccccccc",20},{"ddddd",16}};
	int sz=sizeof(s)/sizeof(s[0]);
	qsort(s,sz,sizeof(s[0]),cmp_stu_name);

	int i=0;
	struct Stu *p=s;
	for(i=0; i<sz; i++) {
		printf("%s\n",p->name);
		p++;
	}
}
int main() {
	test_age();
	test_name();
	return 0;
}










