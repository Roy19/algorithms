#include <stdio.h>
#include <string.h>

#define multiply(A,B,C)	{\
				C[0][0] = (A[0][0]*B[0][0] + A[0][1]*B[1][0]);\
				C[0][1] = (A[0][0]*B[0][1] + A[0][1]*B[1][1]);\
				C[1][0] = (A[1][0]*B[0][0] + A[1][1]*B[1][0]);\
				C[1][1] = (A[1][0]*B[0][1] + A[1][1]*B[1][1]);\
			}

int main(int argc,char *argv[]){
	int matrix[2][2] = {{1,1},{1,0}};
	int fibonacci[2][2] = {{1,1},{1,0}};
	int multiply[2][2];
	int i = 1,n;
	scanf("%d",&n);

	for(i = 1;i < n;i++){
		multiply(fibonacci,matrix,multiply);
		memcpy(fibonacci,multiply,sizeof(int)*4);
	}
	printf("%d\n",fibonacci[0][1]);

	return 0;
}
