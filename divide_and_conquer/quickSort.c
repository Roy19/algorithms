#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_SIZE	10000000

typedef int (*cmp_ptr)(int a,int b);

int compare(int a, int b){
	return (a < b)?-1:(a > b)?1:0;
}

void swap(int * a,int * b){
	int temp = *b;
	*b = *a;
	*a = temp;
}

int partition(int * arr,int low,int high,cmp_ptr cmp){
	int pivot = arr[low];
	int i = low, j = low + 1;

	for(j = low + 1;j <= high;j++){
		if(cmp(arr[j],pivot) <= 0){
			i = i + 1;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[low],&arr[i]);

	return i;
}
void quickSort(int * array,int low,int high){
	int p;
	if(low < high){
		p = partition(array,low,high,compare);
		quickSort(array,low,p-1);
		quickSort(array,p+1,high);
	}
}

void print_array(int * arr,int size,char * msg){
	int i;
	if(msg != NULL)
		printf("%s",msg);
	
	for(i = 0;i < size;i++)
		printf("%d,",arr[i]);
	printf("\n");
}

int isSorted(int * array,int size,cmp_ptr cmp){
	int i = 0;
	for(i = 0; i < size - 1; i++){
		if(cmp(array[i],array[i+1]) > 0){
			printf("array[%d] = %d, array[%d] = %d\n",i,array[i],i+1,array[i+1]);
			return i;
		}
	}
	return 0;
}

int main(int argc,char * argv[]){
	int * array;
	int i,rc,array_size = DEFAULT_SIZE;

	if(NULL == (array = malloc(array_size * sizeof(int)))){
		return -1;
	}
	
	srand(time(NULL));
	
	for(i = 0;i < array_size;i++){
		array[i] = rand();
	}
	
	//print_array(array,array_size,"The initial array:");
	quickSort(array,0,array_size - 1);
	if((rc = isSorted(array,array_size,compare)) != 0){
		printf("Sorting Failed!\ni = %d\n",rc);
	}else{
		printf("Sorting Passed!\n");
	}
	//print_array(array,array_size,"After sorting:");

	free(array);
	return 0;
}
