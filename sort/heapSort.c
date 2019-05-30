#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MaxHeapify(int *, int, int);

void BuildMaxHeap(int *, int);

void HeapSort(int *, int);

void swap(int *, int *);

int main(){
	int A[] = {3,9,4,6,1,7,5,78,34,12,99};
	int size = sizeof(A) / sizeof(A[0]);
	HeapSort(A, size);
	int i;
	for(i = 0; i < size; ++i){
		printf("%d  ", A[i]);
	}
	printf("\n");
	return 0;
}

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void MaxHeapify(int *A, int size, int n){
	int left = 2 * n + 1;
	int right = 2 * n + 2;
	int largest = n;
	if(left <= size - 1 && A[left] > A[n]){
		largest = left;
	}
	if(right <= size - 1 && A[right] > A[largest]){
		largest = right;
	}
	if(largest != n){
		swap(A + largest, A + n);
		/**/
		MaxHeapify(A, size, largest);
	}
}

void BuildMaxHeap(int *A, int size){
	int i;
	for(i = size / 2; i >= 0; --i){
		MaxHeapify(A, size, i);
	}
}

void HeapSort(int *A, int size){
	int i;
	for(i = size; i > 0; --i){
		BuildMaxHeap(A, i);
		swap(A, A + i - 1);
	}
}
