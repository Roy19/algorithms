#include <stdio.h>

int recursiveActivitySelection(int * s, int * f, int k, int n){
	int m = k+1;
	while(m < n && s[m] < f[k])
		m = m+1;

	if(m < n)
		return 1 + recursiveActivitySelection(s,f,m,n);
	else
		return 0;

}
int main(){
	int s[] = {0,1,3,0,5,3,5,6,8,8,2,12};
	int f[] = {0,4,5,6,7,9,9,10,11,12,14,16};

	int n = sizeof(s) / sizeof(int);

	int max = recursiveActivitySelection(s, f, 0, n);
	printf("%d\n", max);

	return 0;
}
