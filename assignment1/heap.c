#include"pa1.h"


//creates an empty heap of given cap
heap create_heap(unsigned capacity){
  heap h;
  h.data = (int*)malloc((1 + capacity)*sizeof(int));
  h.size = 0;
  h.capacity = capacity;
  return h;
}
heap clone(heap h){
  heap copy = h;
  copy.data = (int*)malloc((1 + h.capacity)*sizeof(int));
  for(int i = 0; i < h.capacity+1;i++)
    copy.data[i] = h.data[i];
  return copy;
}
int is_empty(heap h){
  return h.size == 0;
}
int is_full(heap h){
  return h.size == h.capacity;
}
void clear(heap* h){
  h->size = 0;
}
//heapify or max-percolate-down is essential for delete root operation
void max_percolate_down(heap h, int node){//log(n) operation
  //fixes the max-heap property violated by node!
  while(1){
    int left_child = node << 1;
    int right_child = left_child + 1;
    int max = node;
    if(left_child <= h.size && h.data[left_child] > h.data[node])
      max = left_child;
    if(right_child <=h.size && h.data[right_child] > h.data[max])
      max = right_child;
    if(max != node){//swap the node with its largest child
      int temp = h.data[node];
      h.data[node] = h.data[max];
      h.data[max] = temp;
      node = max;
    }else//end of story!
      break;
  }
}
//insert function adds an item to a given max_heap passed by reference
//O(log n) operation that uses percolate-up to preserve max-heap property
void max_insert(heap *h, int item){
  if(h->size == h->capacity)
    return;
  printf("%d enqueued to max priority queue\n", item);
  int index = ++h->size;
  h->data[index] = item;
  while(index != 1){//max percolate-up
    int parent = index >> 1;
    if(h->data[parent] > h->data[index])
      return;
    int temp = h->data[parent];
    h->data[parent] = h->data[index];
    h->data[index] = temp;
    index = parent;
  }
}
//max_delete function removes the root of a max_heap
//O(log n) operation that uses percolate-down to preserve max-heap property
int max_delete(heap *h){
  if(h->size == 0)
    return INT_MIN;
  int rv = h->data[1];//root
    printf("%d dequeued from max priority queue\n", rv);
  h->data[1] = h->data[h->size--];
  max_percolate_down(*h, 1);
  return rv;
}
int get_max(heap h){
  if(h.size == 0)
    return INT_MIN;
  return h.data[1];
}
//heapify or min-percolate-down is essential for delete root operation
void min_percolate_down(heap h, int node){//log(n) operation
  //fixes the min-heap property violated by node!
  while(1){
    int left_child = node << 1;
    int right_child = left_child + 1;
    int min = node;
    if(left_child <= h.size && h.data[left_child] < h.data[node])
      min = left_child;
    if(right_child <=h.size && h.data[right_child] < h.data[min])
      min = right_child;
    if(min != node){//swap the node with its smallest child
      int temp = h.data[node];
      h.data[node] = h.data[min];
      h.data[min] = temp;
      node = min;
    }else//end of story!
      break;
  }
}
//insert function adds an item to a given min_heap passed by reference
//O(log n) operation that uses percolate-up to preserve min-heap property
void min_insert(heap *h, int item){
  if(h->size == h->capacity)
    return;
    //printf("%d enqueued to min priority queue\n", item);
  int index = ++h->size;
  h->data[index] = item;
  while(index != 1){//min percolate-up
    int parent = index >> 1;
    if(h->data[parent] < h->data[index])
      return;
    int temp = h->data[parent];
    h->data[parent] = h->data[index];
    h->data[index] = temp;
    index = parent;
  }
}
//min_delete function removes the root of a min_heap
//O(log n) operation that uses percolate-down to preserve min-heap property
int min_delete(heap *h){
  if(h->size == 0)
    return INT_MAX;
  int rv = h->data[1];//root
    //printf("%d dequeued from min priority queue\n", rv);
  h->data[1] = h->data[h->size--];
  min_percolate_down(*h, 1);
  return rv;
}
int get_min(heap h){
  if(h.size == 0)
    return INT_MAX;
  return h.data[1];
}
