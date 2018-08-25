// Job Sequencing problem suing greedy method

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct job{
    int id;
    int deadline;
    int profit;
}Job;

int cmp(const void * J1, const void * J2){
    if(((Job *)J1)->profit > ((Job *)J2)->profit)
        return -1;
    return 1;
}

void jobSequencing(int n, Job *jList){
    // sort data in descending order of profit
    qsort(jList, n, sizeof(Job), cmp);
    int i, j, count = 0, totalProfit = 0;
    
    // Assuming max deadline is 100
    bool deadline[100];
    memset(deadline, false, sizeof(bool) * 100);

    // Iterate through the list of jobs
    for(i = 0; i < n; i++){
        Job job = jList[i];

        // if a job can be placed in a slot to be completed
        for(j = job.deadline - 1; j >= 0; j--){
            if (deadline[j] == false){
                deadline[j] = true;
                ++count;        // count the number of jobs
                totalProfit += job.profit;  // add the profit
                break;  // done with this job
            }
        }
    }

    // echo the results
    printf("%d %d\n", count, totalProfit);
}

// Test driver
int main() {
	int t;
	scanf("%d", &t);
	
	while(t--){
	    int n, i;
	    scanf("%d", &n);
	    Job jList[n];
	    
	    for(i = 0; i < n; i++)
	        scanf("%d%d%d", &jList[i].id, &jList[i].deadline, &jList[i].profit);
	    
	    jobSequencing(n, jList);
	}
	
	return 0;
}
