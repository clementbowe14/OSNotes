#include "process.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct CircularProcessQueue {
    int front, rear;
    int size;
    unsigned capacity;
    ProcessNode** array;
} CircularProcessQueue;


CircularProcessQueue create(unsigned capacity){
    CircularProcessQueue queue;
    queue.capacity = capacity;
    queue.front = 0;
    queue.rear = 0;
    queue.size = 0;
    queue.array = (ProcessNode*)malloc(queue.capacity * sizeof(ProcessNode));
    return queue;
}

int isFull(CircularProcessQueue queue)
{
    return (queue.size == queue.capacity);
}

// Queue is empty when size is 0
int isEmpty(CircularProcessQueue queue)
{
    return (queue.size == 0);
}

void enqueue(CircularProcessQueue* queue, ProcessNode* item){
    if(isFull(*queue)){
        return;
    } 
    queue -> array[queue -> rear] = item;
    queue -> rear = (queue -> rear + 1) % queue -> capacity;
    queue -> size++;
}

ProcessNode* dequeue(CircularProcessQueue *queue) {
    if(isEmpty(*queue)){
        return NULL;
    }

    ProcessNode* item = queue -> array[queue -> front];
    queue -> front =(queue -> front + 1) % queue -> capacity;
    queue -> size--;
}

ProcessNode* front(CircularProcessQueue queue) {
    if(isEmpty(queue)){
        return NULL;
    }

    return &queue.array[queue.front];
}

ProcessNode* rear(CircularProcessQueue queue) {
    if(isEmpty(queue)){
        return NULL;
    }

    if(queue.rear)
        return queue.array[queue.rear-1];
    else
        return queue.array[queue.capacity-1];
}

void shift(CircularProcessQueue* queue) {
    queue -> front = (queue -> front + 1) % queue -> capacity;
    queue -> rear = (queue -> rear + 1) % queue -> capacity;
}