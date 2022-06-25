#include <stdlib.h>
#include <stdio.h>
#include "process.h"
#include "srtheap.h"
#include "utils.h"
#include "process_queue.h"


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
    ProcessQueue newNodes = createProcessQueue();
    ProcessQueue terminatedNodes = createProcessQueue();
    heap scheduler = create_heap(n);

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

    printf("adding nodes to newNode queue\n");
    for(int i = 0; i < n; i++){
        enqueue(&newNodes, &nodes[i]);
    }

    int time = 0;
    int i = n;

    while(terminatedNodes.size < n){
    
    if(scheduler.size > 0){
        ProcessNode* node = peek(&scheduler);
        node -> remainingTime--;
        if(node -> remainingTime == 0){
            enqueue(&terminatedNodes, delete(&scheduler));
        }
    }

        while(isEmpty(newNodes) == 0 && front(&newNodes)->arrivalTime <= time){
            min_insert(&scheduler, dequeue(&newNodes));
            terminatedNodes.size++;
        }

        if(newNodes.size > 0){
            printQueue(newNodes);
        }

        if(terminatedNodes.size > 0){
            printQueue(terminatedNodes);
        }
        time++;
    }



}