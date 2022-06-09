


struct ProcessNode {
    int pid;
    int arrivalTime; //
    int priorityLevel;
    int cpuTime;
    int isActive;  // active = 1 new or terminated = 0
    int processState; // terminated = 0 new = 1 active = 2
    struct ProcessNode * next;
};

struct ProcessNode* createProcess(int id, int aTime, int pLevel, int cpu, int act, int state, struct ProcessNode next);
void activateProcess(struct ProcessNode * p);
void deactivateProcess(struct ProcessNode * p);
void lowerPriority(struct ProcessNode *p);
void decrementCPUTime(struct ProcessNode *p);
int isFinished(struct ProcessNode *p);
