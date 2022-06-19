#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <limits.h>

typedef struct node {
    struct node * next;
    ProcessNode* value;
} node;

 typedef struct ProcessQueue{
     node* head;
     node* tail;
     int size;
}ProcessQueue;



ProcessQueue createProcessQueue(){
    ProcessQueue queue;
    queue.size = 0;
    queue.head = queue.tail = (node*)malloc(sizeof(node));
    //dummy node
    createNode(queue.head -> value, INT_MIN, -1, -1,-1, -1, -1, -1);
    queue.head -> next = NULL;
    return queue;
}


int isEmpty(ProcessQueue queue) {
    return (queue.size == 0);
}

ProcessNode* dequeue(ProcessQueue* queue) {
    node* deleted = queue -> head -> next;
    ProcessNode* res = deleted ->value;
    queue -> head -> next = deleted -> next;
    queue -> size--;
    if(queue -> tail == deleted)
        queue -> tail = queue -> head;

    free(deleted);

    return res;
}

void enqueue(ProcessQueue* queue, ProcessNode* item){
    queue -> tail -> next = (node*)malloc(sizeof(node));
    queue -> tail -> next -> next = NULL;
    queue -> tail -> next -> value = item;
    queue -> size++;
}

ProcessNode* front(ProcessQueue* queue) {
    if(isEmpty(*queue))
        return NULL;
    return queue -> head -> next -> value;
}

