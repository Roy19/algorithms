#include <stdio.h>
#include <string.h>

int main(){
	// Write your code here
  	int n,i = 0,j;
 	scanf("%d",&n);
  	int a[n];
  	int b[n];
  	int count[100001];

  	memset(b,0,sizeof(b));
  	memset(count,0,sizeof(count));
  	
  	while(i < n){
                scanf("%d",&a[i]);
                ++count[a[i]];	// find the number of entries
                ++i;
        }
  	// find the multiples using sieve method
  	for(i = 0;i < n;i++){
      	        int num = a[i];
      	        for(j = num;j < 100001;j += num){
          	        b[i] += count[j];
                }
        }
  	
  	// print the b array
  	for(i = 0;i < n;i++){
      	        printf("%d ",b[i]);
        }
        printf("\n");
	return 0;
}