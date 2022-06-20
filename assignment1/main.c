#include <stdlib.h>
#include <stdio.h>
#include "process.h"
#include "srtheap.h"
#include "utils.h"



int main(int argc, char *argv[]) {

    printf("number of args, %d\n", argc);
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    int d = atoi(argv[3]);
    int v = atoi(argv[4]);

    printf("n%d\nk%d\n d %d\n v %d\n", n, k, d, v);
    int * totalCPUTimes = malloc(n * sizeof(double));
    int * arrivalTimes = malloc(n * sizeof(int));
    ProcessNode* nodes = malloc(n * sizeof(struct ProcessNode));
    
    //uniform distribution of arrival times
    createUniformlyDistributedList(arrivalTimes, n, 0, k);

    //normal distribution of total cpu time
    createNormallyDistributedList(totalCPUTimes, n, d, v);

    printf("created cpu times times for the processes%s\n", "");
    for(int i = 0; i < n; i++) {
        createNode(&nodes[i], i, arrivalTimes[i], 0, totalCPUTimes[i], totalCPUTimes[i], 1, 1);
    }
    printf("created process data structures %s\n", "");
    
    sortProcesses(nodes, n);

    printf("adding nodes to process queue");
    for(int i = 0; i < n; i++){

    }


}