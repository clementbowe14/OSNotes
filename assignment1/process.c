
#include <stdlib.h>

struct ProcessNode {
    int pid;
    int arrivalTime; //
    int priorityLevel;
    int cpuTime;
    int isActive;  // active = 1 new or terminated = 0
    int processState; // terminated = 0 new = 1 active = 2
    struct ProcessNode * next;
};

struct ProcessNode* createProcess(int id, int aTime, int pLevel, int cpu, int act, int state, struct ProcessNode * next) {
    struct ProcessNode p;
    p.pid = id;
    p.arrivalTime = aTime;
    p.priorityLevel = pLevel;
    p.cpuTime = cpu;
    p.isActive = act;
    p.processState = state;
    p.next = next;

    return &p;
}

void activateProcess(struct ProcessNode * p) {
    if(p != NULL)
       p -> isActive = 1;
}

void deactivateProcess(struct ProcessNode * p) {
    if(p != NULL)
    p -> isActive = 0;
}

void lowerPriority(struct ProcessNode *p) {
    if(p != NULL)
        p ->priorityLevel--;
}

void decrementCPUTime(struct ProcessNode *p) {
    if(p != NULL)
        p -> cpuTime--;
}

int isFinished(struct ProcessNode *p) {
    if(p -> cpuTime == 0)
        return 1;
    return 0;
}






