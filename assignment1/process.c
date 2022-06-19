
#include <stdlib.h>

typedef struct ProcessNode {
    int pid;
    int arrivalTime; //
    int priorityLevel;
    int totalCpuTime;
    int remainingTime;
    int isActive;  // active = 1 new or terminated = 0
    int processState; // terminated = -1 new = 0 active = 1
    struct ProcessNode* next;
}ProcessNode;


//create nodes that do not need to be linked
void createNode(ProcessNode* p, int id, int aTime, int pLevel, int cpu, int rem, int act, int state){
    p -> pid = id;
    p -> arrivalTime = aTime;
    p -> priorityLevel = pLevel;
    p -> totalCpuTime = cpu;
    p -> remainingTime = rem;
    p -> isActive = act;
    p -> processState = state;
}

void activateProcess(ProcessNode * p) {
    if(p != NULL)
       p -> isActive = 1;
}

void deactivateProcess(ProcessNode * p) {
    if(p != NULL)
    p -> isActive = 0;
}

void terminateProcessState(ProcessNode *p) {
    p -> processState = -1;
}

void newProcessState(ProcessNode *p) {
    p -> processState = 0;
}

void readyProcessState(ProcessNode *p) {
    p -> processState = 1;
}

void lowerPriority(ProcessNode *p) {
    if(p != NULL)
        p ->priorityLevel--;
}

void decrementCPUTime(struct ProcessNode *p) {
    if(p != NULL)
        p -> remainingTime--;
}


int isFinished(ProcessNode *p) {
    if(p -> remainingTime == 0)
        return 1;

    return 0;
}







