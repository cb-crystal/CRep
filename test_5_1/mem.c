#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>
//void* my_memcpy(void* des,const void* src, size_t num){
//	void* start = des;
//	assert(des != NULL&&src != NULL);
//	while (num--){
//		*(char*)des = *(char*)src;
//		((char*)des)++;
//		((char*)src)++;
//	}
//	return start;
//}
//int main(){
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	char arr2[10] = {0};
//	my_memcpy(arr2,arr,20);
//
//	return 0;
//}
//实现memmove函数
//void* my_memmove(void* des, const void* src, size_t num){
//	void* start = des;
//	if (des <src){
//		//从前往后
//		while (num--){
//			*(char*)des = *(char*)src;
//			((char*)des)++;
//			((char*)src)++;
//		}
//	}
//	else{
//		while (num--){
//			*((char*)des + num) = *((char*)src + num);
//		}
//	}
//	return start;
//}
//int main(){
//	int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	my_memmove(arr2 , arr2+1, 20);
//	for (int i = 0; i < 10; i++){
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}
//int my_memcmp(const void* arr1, const void* arr2, size_t num){
//	assert(arr1 != NULL&&arr2 != NULL);
//	while ((num--) && (*(char*)arr1 == *(char*)arr2)){
//		if (num == 0){
//			return 0;
//		}
//		((char*)arr1)++;
//		((char*)arr2)++;
//	}
//	return *(char*)arr1 - *(char*)arr2;
//}
//int main(){
//	int arr[] = { 1, 2, 5, 4, 5, 6, 7, 8, 9, 10 };
//	int arr2[] = { 1, 2, 5, 5, 7, 2 };
//	int ret = my_memcmp(arr, arr2, 16);
//	if (ret <0){
//		printf("arr<arr2");
//	}
//	else if (ret > 0){
//		printf("arr>arr2");
//	}
//	else{
//		printf("arr=arr2");
//	}
//	return 0;
//}
//memset()函数将一个数据放进另一个目标地址处，放几个字节
//int main(){
//	char arr[] = "almost";
//	memset(arr, '1', 3);
//	printf("%s ", arr);
//	return 0;
//}