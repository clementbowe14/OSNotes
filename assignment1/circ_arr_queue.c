// C program for array implementation of queue
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
 
// A structure to represent a queue using circular array
struct queue1{
    int front, rear, size;
    unsigned capacity;
    int* array;
};
typedef struct queue1 circ_arr_queue;
 
// function to create a queue
// of given capacity.
// It initializes size of queue as 0
circ_arr_queue create_queue1(unsigned capacity)
{
    circ_arr_queue queue;
    queue.capacity = capacity;
    queue.front = queue.size = queue.rear = 0;
    queue.array = (int*)malloc(
        queue.capacity * sizeof(int));
    return queue;
}
 
// Queue is full when size becomes
// equal to the capacity
int is_full1(circ_arr_queue queue)
{
    return (queue.size == queue.capacity);
}
 
// Queue is empty when size is 0
int is_empty1(circ_arr_queue queue)
{
    return (queue.size == 0);
}
 
// Function to add an item to the queue.
// It changes rear and size
void enqueue1(circ_arr_queue* queue, int item)
{
    if (is_full1(*queue))
        return;
  queue->array[queue->rear] = item;
    queue->rear = (~queue->rear + queue->capacity)?
      queue->rear + 1: 0;//circular array!
    queue->size++;
    printf("%d enqueued to queue\n", item);
}
 
// Function to remove an item from queue.
// It changes front and size
int dequeue1(circ_arr_queue *queue)
{
  if (is_empty1(*queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (~queue->front + queue->capacity)?
      queue->front + 1: 0;//circular array!
    queue->size--;
    return item;
}
 
// Function to get front of queue
int front1(circ_arr_queue queue)
{
    if (is_empty1(queue))
        return INT_MIN;
    return queue.array[queue.front];
}
 
// Function to get rear of queue
int rear1(circ_arr_queue queue)
{
    if (is_empty1(queue))
        return INT_MIN;
    if(queue.rear)  
      return queue.array[queue.rear - 1];
    else
      return queue.array[queue.capacity - 1];
}
 
