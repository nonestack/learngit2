#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int swap(int *, int *);

void quickSort(int *, int, int);

int main(){
	int A[20] = {0};
	int tmp;
	srand(time(NULL));
	int i;
	for(i = 0; i < 20; ++i){
		tmp = rand() % 100;
		A[i] = tmp;
	}
	for(i = 0; i < 20; ++i){
		printf("%d  ", A[i]);
	}
	printf("\n");
	quickSort(A, 0, 20);
	for(i = 0; i < 20; ++i){
		printf("%d  ", A[i]);
	}
	printf("\n");
	return 0;
}

int swap(int *a, int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return 0;
}

void quickSort(int *A, int low, int high){
	if(low > high) 
		return ;
	int i = low, j = high, base = A[low];
	while(i < j){
		while(i < j && A[j] >= base) --j;
		while(i < j && A[i] <= base) ++i;
		if(i < j)
			swap(A + i, A + j);
	}
	swap(A + low, A + j);
	quickSort(A, low, j - 1);
	quickSort(A, j + 1, high);
}
