#include <process.h>

typedef struct node {
    struct node * next;
    ProcessNode* value;
} node;

 typedef struct ProcessQueue{
     node* head;
     node* tail;
     int size;
}ProcessQueue;

ProcessQueue createProcessQueue();
int isEmpty(ProcessQueue q);
ProcessNode* dequeue(ProcessQueue* queue);
void enqueue(ProcessQueue* q, ProcessNode* item);
ProcessNode* front(ProcessQueue* queue);
