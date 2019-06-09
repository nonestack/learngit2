#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int bitSort(int *nums, int numsSize){
	int A[10] = {0};
	int i, k;
	for(i = 0; i < numsSize; ++i){
		printf("%d ", nums[i]);
	}
	printf("\n");
	for(i = 0; i < numsSize; ++i){
		//++A[i];
		++A[nums[i]];
	}
	//for(i = 0; i < 10; ++i){
	//	printf("%d ", A[i]);
	//}
	//printf("\n");
	for(i = 0, k = 0; i < numsSize && k < 10; ++i){
		while(A[k] == 0 && k < 10){
			++k;
		}
		if(k >= 10){
			break;
		}
		if(A[k] != 0){
			nums[i] = k;
			--A[k];
		}
	}
	return 0;
}

int main(){
	int A[12] = {0};
	srand(time(NULL));
	int i;
	int arrLen = sizeof(A) / sizeof(A[0]);
	for(i = 0; i < arrLen; ++i){
		A[i] = rand() % 10;
	}
	bitSort(A, arrLen);
	for(i = 0; i < arrLen; ++i){
		printf("%d  ", A[i]);
	}
	printf("\n");
	return 0;
}
