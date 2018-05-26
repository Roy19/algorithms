#include <stdio.h>
#include <stdlib.h>

/* Finds the nth fibonacci number starting from 0.
 * Uses Dynamic Programming (Memoization) to solve the problem.
 * Time Complexity = O(n). Cause we only compute each element once.
 * Space Complexity = O(n+1)
*/
long fibonacci_memoization(int n,int *memo){
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	if(memo[n] == 0){
		memo[n] = fibonacci_memoization(n-1,memo)+fibonacci_memoization(n-2,memo);
	}else{
		return memo[n];
	}
}
int main(int argc,char *argv[]){
	int n;
	scanf("%d",&n);
	// create a cache to store previously calculated elements
	int *memo = calloc(n+1,sizeof(int));
	printf("%ld\n",fibonacci_memoization(n,memo));
	// free up the cache
	free(memo);
	return 0;
}
