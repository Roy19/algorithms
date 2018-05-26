#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

int * countingSort(int * array,size_t size,int max){
	check(array != NULL && size != 0,"Invalid parameters to countingSort()");

	int i,*c,*b;
	c = calloc(max+1,sizeof(int));
	check_mem(c);
	b = calloc(size,sizeof(int));
	check_mem(b);

	for(i = 0;i < size;i++)
		c[array[i]] += 1;
	
	for(i = 1;i <= max;i++)
		c[i] +=  c[i-1];

	for(i = size-1;i >= 0;i--){
		b[c[array[i]]-1] = array[i];
		c[array[i]] -= 1;
	}
	
	free(c);
	return b;
error:
	return NULL;
}
int main(){
	int array[] = {5,4,3,8,2,1,8,0,0,5,5,3,4,9,9,6,3,3,7};
	size_t size = sizeof(array)/sizeof(int);
	int i,max = array[0];
	
	for(i = 1;i < size;i++){
		if(array[i] > max){
			max = array[i];
		}
	}
	
	printf("Before sorting the array is:");
	for(i = 0;i < size;i++)
		printf("%d ",array[i]);
	printf("\n");
	
	int * x = countingSort(array,size,max);
	check(x != NULL,"Couldn't sort the array");

	printf("After sorting the array becomes:");
	for(i = 0;i < size;i++)
		printf("%d ",x[i]);
	printf("\n");
	
	free(x);
	return 0;
error:
	return 1;
}
