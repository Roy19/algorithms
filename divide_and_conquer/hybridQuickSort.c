// Running time T(n) = O(nk + n lg (n/k))

#include <stdio.h>

int list[] = { 20, 89, 75, 1, -3, 0, 45, 79, 4, 10, 76, 100, 44 };

void swap(int * a, int * b){
		int temp = *a;
		*a = *b;
		*b = temp;
}

void insertionSort(int * A, int low, int high) {
	if (low < high) {
		for (int i = low + 1; i <= high; i++) {
			int pivot = A[i];
			int j = i - 1;
			while (j >= low && A[j] > pivot) {
				A[j + 1] = A[j];
				--j;
			}
			A[j+1] = pivot;
		}
	}
}

int partition(int * A, int p, int q) {
	int pivot = A[p];
	int i = p - 1;
	int j = q + 1;
	while (1) {
		while (A[++i] < pivot);
		while (pivot < A[--j]);

		if (i >= j)
			return j;
		else
			swap(&A[i], &A[j]);
	}
}

void hybridSort(int * A, int p, int q,int k) {
	if (q - p + 1 < k) {
		int r = partition(A, p, q);
		hybridSort(A, p, r, k);
		hybridSort(A, r + 1, q, k);
	}
}
int main()
{
	int length = sizeof(list) / sizeof(int);
	printf("Initially the array is:");
	for (int i = 0; i < length; i++) {
		printf("%d ",list[i]);
	}

	hybridSort(list, 0, length - 1, 4);				// here I used the value of 4. But any value suitable to the
	insertionSort(list, 0, length - 1);				// system maybe used. Generally 9 or 10 is used.

	printf("\nAfter sorting, the array is:");
	for (int i = 0; i < length; i++) {
		printf("%d ",list[i]);
	}
	
	printf("\n");

	return 0;
}