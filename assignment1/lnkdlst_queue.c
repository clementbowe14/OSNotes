// C program for linkedlist implementation of queue
#include "pa1.h"
 
// function to create a queue
// It initializes size of queue as 0
lnklst_queue create_queue2()
{
    lnklst_queue queue;
    queue.size = 0;
    process p;
    p.arrival_time = -1;//dummy process
  //when empty, queue has a dummy node
    queue.head = queue.tail = (node*)malloc(sizeof(node));
  queue.head->value = p;//dummy
  queue.head->next = NULL;//dummy is the last!
  return queue;
}
 
// Queue is empty when size is 0
int is_empty2(lnklst_queue queue)
{
    return (queue.size == 0);
}
 
// Function to add an item to the queue.
// It adds a node to tail of linked list
void enqueue2(lnklst_queue* queue, process item)
{
  queue->tail->next = (node*)malloc(sizeof (node));
  queue->tail->next->next = NULL;
  queue->tail->next->value = item;
  queue->tail = queue->tail->next;
  queue->size++;
}
 
// Function to remove an item from queue.
// It adds a node to the head of linked list
process dequeue2(lnklst_queue* queue)
{
    if (is_empty2(*queue)){
      process p;
      p.arrival_time = -1;//dummy process
      return p;
    }
        
    node* deleted = queue->head->next;
    process item = deleted->value;
    queue->head->next = deleted->next;
    queue->size--;
    if(queue->tail == deleted)
      queue->tail = queue->head;
    free(deleted);
    return item;
}
 
// Function to get the front of queue
process front2(lnklst_queue queue)
{
    if (is_empty2(queue)){
      process p;
      p.arrival_time = -1;//dummy process
      return p;
    }
    return queue.head->next->value;
}
 
// Function to get rear of queue
process rear2(lnklst_queue queue)
{
    if (is_empty2(queue)){
      process p;
      p.arrival_time = -1;//dummy process
      return p;
    }
    return queue.tail->value;
}
