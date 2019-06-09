#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return 0;
}

int MaxHeapify(int *A, int n, int size){
	int right = n * 2 + 2;
	int left = n * 2 + 1;
	int max = n;
	if(right < size && A[right] > A[max]){
		max = right;
	}	
	if(left < size && A[left] > A[max]){
		max = left;
	}
	if(max != n){
		swap(A + max, A + n);
		MaxHeapify(A, max, size);
	}
	return 0;
}

int BuildHeap(int *A, int size){
	int i; 
	for(i = size - 1; i >= 0; --i){
		MaxHeapify(A, i, size);
	}
	return 0;
}

int heapSort(int *A, int arrLen){
	int i;
	for(i = arrLen; i > 0; --i){
		BuildHeap(A, i);
		swap(A + 0, A + i - 1);
	}
	return 0;
}


int main(){
	int A[10] = {0};
	int arrayLen = sizeof(A) / sizeof(A[0]);
	srand(time(NULL));
	int i;
	for(i = 0; i < arrayLen; ++i){
		A[i] = rand() % 100;
	}
	heapSort(A, arrayLen);
	for(i = 0; i < arrayLen; ++i){
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}

