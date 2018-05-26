#include <stdint.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct tuple_{
	uint32_t left_pos;
	uint32_t right_pos;
	int sum;
}tuple;

tuple * findMaxCrossing(int * array,int from,int middle,int to){
	int i,sum = 0;
	int left_sum = INT_MIN,right_sum = INT_MIN;
	uint32_t left_pos = (uint32_t)middle;
	uint32_t right_pos = (uint32_t)middle;
	tuple * ret;
	for(i = middle;i >= from;i--){
		sum += array[i];
		if(sum > left_sum){
			left_sum = sum;
			left_pos = (uint32_t)i;
		}
	}
	sum = 0;
	for(i = middle + 1;i <= to;i++){
		sum += array[i];
		if(sum > right_sum){
			right_sum = sum;
			right_pos = (uint32_t)i;
		}
	}
	if((ret = calloc(1,sizeof(tuple))) == NULL){
		return NULL;
	}
	ret->left_pos = left_pos;
	ret->right_pos = right_pos;
	ret->sum = left_sum + right_sum;
	
	return ret;
}
tuple * findMaxSubArray(int * array,int from,int to){
	tuple * ret, * left_ret, * right_ret;
	if(to == from){
		ret = calloc(1,sizeof(tuple));
		if(ret == NULL)
			return NULL;
		
		ret->left_pos = (uint32_t)from;
		ret->right_pos = (uint32_t)to;
		ret->sum = array[from];
		
		return ret;
	}else{
		int middle = from + (to-from) / 2;
		left_ret = findMaxSubArray(array,from,middle);
		right_ret = findMaxSubArray(array,middle+1,to);
		ret = findMaxCrossing(array,from,middle,to);
		
		if((left_ret->sum > right_ret->sum) && (left_ret->sum && ret->sum)){
			free(ret);
			free(right_ret);
			return left_ret;
		}
		else if((right_ret->sum > left_ret->sum) && (right_ret->sum > ret->sum)){
			free(left_ret);
			free(ret);
			return right_ret;
		}
		else{
			free(left_ret);
			free(right_ret);
			return ret;
		}
	}
}
int main(){
	int array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	tuple * ans = findMaxSubArray(array,0,(sizeof(array) / sizeof(int)) - 1);
	printf("left_pos = %d, right_pos = %d, sum = %d",ans->left_pos,ans->right_pos,ans->sum);
	
	free(ans);
	return 0;
}