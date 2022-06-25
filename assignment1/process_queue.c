#include "process.h"

#include <stdio.h>
#include <stdlib.h>
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
    printf("creating process queue");
    ProcessQueue queue;
    queue.size = 0;
    queue.head = queue.tail = (node*)malloc(sizeof(node));
    //dummy node
    queue.head -> value = (ProcessNode*)malloc(sizeof(ProcessNode));
    createNode(queue.head -> value, INT_MIN, -1, -1,-1, -1, -1, -1);
    queue.head -> next = NULL;
    return queue;
}


int isEmpty(ProcessQueue queue) {
    if(queue.size > 0){
        return 0;
    }
    return 1;
}

ProcessNode* dequeue(ProcessQueue* queue) {
    node* deleted = queue -> head -> next;
    ProcessNode* res = deleted ->value;
    queue -> head -> next = deleted -> next;
    queue -> size--;
    if(queue -> tail == deleted)
        printf("We have reached the tail");
        queue -> tail = queue -> head;

    free(deleted);

    return res;
}

void enqueue(ProcessQueue* queue, ProcessNode* item){
    queue -> tail -> next = (node*)malloc(sizeof(node));
    queue -> tail -> next -> next = NULL;
    queue -> tail -> next -> value = (ProcessNode*)malloc(sizeof(ProcessNode));
    queue -> tail -> next -> value = item;
    queue -> tail = queue -> tail -> next;
    queue -> size++;
}

ProcessNode* front(ProcessQueue* queue) {
    if(isEmpty(*queue))
        return NULL;
    return queue -> head -> next -> value;
}

