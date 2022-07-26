#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#ifndef SOME_HEADER_GUARD_WITH_UNIQUE_NAME
#define SOME_HEADER_GUARD_WITH_UNIQUE_NAME
typedef struct{
  int arrival_time;
  int burst_time;
  int priority_level;
  int remaining_time;
  int tt;
}process;
typedef struct node{
  struct node* next;
  int value;
}node;
typedef struct queue2{
    node* head;
    node* tail;
    int size;
}lnklst_queue;
#endif
//linked list queue
lnklst_queue create_queue2();
void enqueue2(int val);
int dequeue2();