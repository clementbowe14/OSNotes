#include "process.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    struct ProcessNode** data;
    int size;
    unsigned capacity;
} srtheap;

srtheap create_heap(unsigned capacity){
    srtheap h;
    h.data = malloc((1+capacity) * sizeof(struct ProcessNode*));
    h.size = 0;
    h.capacity = capacity;

    printf("new heap created with size %d and capacity %d\n", h.size, h.capacity);
    return h;
}

int is_empty(srtheap h){
    return h.size == 0;
}

int is_full(srtheap h){
    return h.size == h.capacity;
}

struct ProcessNode *peek(srtheap *h) {
    return h -> data[1];
}


void min_percolate_down(srtheap h, int index) {
    while(1) {
        int left_child = index << 1;
        int right_child = left_child + 1;
        int min = index;
        struct ProcessNode* left = h.data[left_child];
        struct ProcessNode* right = h.data[right_child];
        
        if(left_child <= h.size && left ->remainingTime < h.data[min] ->remainingTime){
            min = left_child;
        }

        if(right_child <= h.size && right -> remainingTime < h.data[min] -> remainingTime){
            min = right_child;
        }

        if(min != index){
            struct ProcessNode* temp = h.data[index];
            h.data[index] = h.data[min];
            h.data[min] = temp;
            index = min;
        } else {
            break;
        }
    }
}

struct ProcessNode* delete(srtheap *h) {
    struct ProcessNode* res = h -> data[1];
    printf("%d process has been deleted from the queue\n", res ->pid);
    h -> data[1] = h -> data[h -> size--];
    min_percolate_down(*h, 1);
    return res;
}


void min_insert(srtheap *h, struct ProcessNode* node){
    if(h -> size == h -> capacity){
        return;
    }
    int index  = ++h -> size;
    h -> data[index] = node;

   printf("process is at index %d is with id %d\n", index, h -> data[index] -> pid);

   while(index != 1){
       int parent = index >> 1;
       if(h -> data[parent] -> remainingTime < h -> data[index] -> remainingTime){
           return;
       }
       struct ProcessNode* temp = h ->data[parent];
       h->data[parent] = h->data[index];
       h->data[index] = temp;
       index = parent;
   }
}

void printSrtHeap(srtheap h) {
    for(int i = 1; i < h.size; i++){
        printf("pid: %d, arrival time: %d, cpu_time: %d", h.data[i]->pid, h.data[i]->arrivalTime, h.data[i] ->totalCpuTime);
    }
}

void addWaitingTime(srtheap* h) {
    
}