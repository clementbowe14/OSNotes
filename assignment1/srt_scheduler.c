#include "process.h"
#include "process_queue.h"
#include "srtheap.h"


typedef struct SrtScheduler {
    ProcessQueue newnodes;
    heap readyNodes;
    ProcessQueue terminatedNodes;
} SrtScheduler;

SrtScheduler createSrtScheduler(unsigned capacity){
    SrtScheduler sch;
    ProcessQueue start = createProcessQueue();
    ProcessQueue end = createProcessQueue();
    sch.readyNodes = create_heap(capacity);
}

//add a process to the new list
void addNewNode(SrtScheduler* sch,  ProcessNode* p){
    enqueue(&sch ->newnodes, p);
}


//add all processes in the new queue with <= atime to the ready list
void addNewNodesToReadyList(SrtScheduler* sch, int atime) {
    while(1){
        if(is_empty(sch ->readyNodes))
            break;

        ProcessNode* curr = front(&sch ->newnodes);
        if(curr -> arrivalTime > atime)
            break;
        min_insert(&sch -> readyNodes, dequeue(&sch -> newnodes));
    }
}
//add node peek node in the ready list to the terminated list if it is
void addReadyNodeToTerminatedList(SrtScheduler* sch) {
    if(sch -> readyNodes.size == 0)
        return;
    
    ProcessNode* top = peek(&sch -> readyNodes);
    if(top -> remainingTime == 0) {
       ProcessNode* newTerminatedNode = delete(&sch -> readyNodes);
       enqueue(&sch ->terminatedNodes, newTerminatedNode);
    }
    
}


