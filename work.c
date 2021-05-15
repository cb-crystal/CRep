#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(){
	//¼ÙÉènÎª10
	int nums[] = {0,1,2,4,5,6,7,8,9,10};
	int lostNum = 0;
	for (int i = 0; i < 10; i++){
		lostNum = lostNum^nums[i] ^ i;
	}
	printf("%d", lostNum);
	return 0;
}