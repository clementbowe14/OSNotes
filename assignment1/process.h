typedef struct ProcessNode  {
    int pid;
    int arrivalTime; //
    int priorityLevel;
    int totalCpuTime;
    int remainingTime;
    int isActive;  // active = 1 new or terminated = 0
    int processState; // terminated = 0 new = 1 active = 2
    struct ProcessNode* next;
 } ProcessNode;

void createNode(ProcessNode* p, int id, int aTime, int pLevel, int cpu, int rem, int act, int state);
void activateProcess(ProcessNode * p);
void deactivateProcess(ProcessNode * p);
void lowerPriority(ProcessNode *p);
void decrementCPUTime(ProcessNode *p);
int isFinished(ProcessNode *p);
void terminateProcessState(ProcessNode *p);
void newProcessState(ProcessNode *p);
void readyProcessState(ProcessNode *p);