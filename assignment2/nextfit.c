#include <stdlib.h>
#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<time.h>
#define frand() (rand()/(double)RAND_MAX)
#define nrand() (sqrt(-2*log(frand()))*cos(2*M_PI*frand()))

double avg_utilization = 0;
int number_of_examined_holes = 0;
int head = 0;//head of the linked list of holes

void initialize(int n, int d, int v, int** mem, int**blocks){
  srand(time(NULL));
  int max_blocks = n/(d-v); ///why?!
  *mem = (int*)malloc(sizeof(int)*n);
  (*mem)[0] = (*mem)[n-1] = -n+2;
  (*mem)[1] = (*mem)[2] = 0;
  *blocks = (int*)malloc(max_blocks*sizeof(int));
}

int mod(int a, int b)
{
  printf("creating modulo %d %d\n", a, b);
  printf("\n");
    int r = a % b;
    return r < 0 ? r + b : r;
}

int nrand_gen(int d, double v, int n){
  double rv;
  do{
    rv=  nrand() * v + d;//use rand function here
    }while(rv < 3 || rv > n-4);
    return rv;
}

int request(int* blocks, int* block_count, int* mem, int d, double v, int n){
  if(head == -1)//no hole is found!
    return 0;

  int size = nrand_gen(d, v, n);
  int iterator = head, pred, succ, new_size, block_address;
  printf("searching for request of size %d\n", size);
  printf("The head of the list is %d\n", head);
  while(size > -mem[iterator]){
    printf("Iterator is currently at location %d with value %d\n", iterator, -mem[iterator]);
    number_of_examined_holes++;
    iterator = mem[iterator + 2];//iterator = iterator->next
    if(head == iterator){
      printf("There is not enough space to fulfill request for %d blocks\n", size);
      return 0;//unsuccessful
    }
  }

  printf("Hole found at location %d will fulfill request for  %d blocks\n", iterator, size);

  if(abs(size+mem[iterator]) <= 4){//fill completely

  printf("Block at location %d will be filled completely to fulfill request.\n", iterator);
    //request size is almost equal to the hole size
    size = -mem[iterator];//block fills hole completely
    mem[iterator] = mem[iterator + size + 1] = size;
    //delete the current hole since it is full now
    pred = mem[iterator+1];
    succ = mem[iterator+2];


    if (pred == iterator)//current hole is the only hole
      head = -1;
    else{
      mem[pred+2] = succ;//current->prev->next = current->next
      mem[succ+1] = pred;//current->next->prev = current->prev 

    //   if(iterator == head){
    //     printf("block allocated was the head of the list at location %d the new head is now  %d \n", iterator, pred);
    //     head = pred;
    //   }
      head = succ;
    }
    block_address = iterator;
  }else{//fill partially
    printf("Block at location %d will be filled partially to fulfill request.\n", iterator);
    head = iterator;
    mem[iterator] += (size+2);
    //adding pos by neg to make it less negative
    new_size = -mem[iterator];
    mem[iterator + new_size + 1] = mem[iterator];
    //block starts at iterator + new_size + 2
    block_address = iterator + new_size + 2;
    mem[block_address] = 
      mem[block_address + size + 1] = size;
  }
  blocks[*block_count] = block_address;
  (*block_count)++;

   for(int i = block_address + 1; i < block_address + size + 1; i++){
     mem[i] = 0;
  }

  printf("New allocated block located at %d\n", block_address);
  // for(int i = 0; i < n; i++){
  //   printf("%d  ", mem[i]);
  // }
  printf("\n");

  return 1;//successful
}

void release(int* blocks, int* block_count, int* mem, int n){
  
  if(!*block_count)
    return;

  int to_be_released = rand()%(*block_count);
  int block_start = blocks[to_be_released];
  int block_end = block_start + mem[block_start] + 1; 
  int prev_start = 0;
  int prev_end = 0;
  int next_start = 0;
  int next_end = 0;
  int new_size = 0;
  int end = 0;

   printf("releasing block at location (address) %d \n", blocks[to_be_released]);

  //remove an integer at index to_be_released from blocks array...
  blocks[to_be_released] = blocks[(*block_count)-1];
  (*block_count)--;

//set the head to the first block that opens up
  if(head == -1){
    printf("A new head was created at index %d\n", block_start);
    head = block_start;
  }

  mem[block_start] = -mem[block_start];
  mem[block_end] = -mem[block_end];
  mem[block_start+1] = block_start;
  mem[block_start+2] = block_start;

  int prev = block_start - 1;
  int next = (block_end + 1) % n;

  prev = mod(prev, n);

  //merging the left and right side
  if(next == block_end + 1 && mem[next] < 0 && prev == block_start-1 && mem[prev] < 0){
    
    printf("merging the left and right side of the hole\n");
    prev_start = prev + mem[prev] - 1;
    next_end = next + (-mem[next]) + 1;
    printf("merging holes (%d, %d, %d,)\n", (prev+mem[prev])-1, block_start, next);
    new_size = mem[block_start] + mem[prev] + mem[next] - 4;
    end = prev_start + (-new_size) + 1;

    printf("New size of hole is now %d\n", -new_size);


    //set unused block in array equal to 0
    mem[block_start] = 0;
    mem[block_end] = 0;
    mem[prev] = 0;
    mem[next] = 0;
    mem[next_end] = 0;

    //set next and prev pointers
    mem[prev_start + 2] = mem[next + 2];
    mem[mem[next+2] + 1] = prev_start;

    if(head == block_start){
      head = prev_start;
    }

    block_start = prev_start;
    block_end = end;
    printf("start and end of the block %d %d\n", block_start, block_end);

    mem[block_start] = new_size;
    mem[block_end] = new_size;

    printf("Creating new hole of size %d\n", -new_size);
   

  } else if(next == block_end + 1 && mem[next] < 0){ // merge with the right side
    
    printf("merging from the right side of the hole\n");
    printf("merging holes (%d, %d)\n", block_start, next);
    new_size = mem[block_start] + mem[next] - 2;
    printf("Creating new hole of size %d\n", -new_size);

    next_end = next + (-mem[next]) + 1;
    end = block_start + (-new_size) + 1;
    
    if(next == head) {
        block_start = head;
    }
    //remove values from former end
    mem[block_end] = 0;
    mem[next] = 0;
    mem[next_end] = 0; 

    //reset pointers
    mem[block_start + 1] = mem[next + 1];
    mem[mem[next + 1] + 2] = block_start;
    mem[block_start + 2] = mem[next + 2];
    mem[mem[next + 2] + 1] = block_start;
    
    block_end = end;
    mem[block_start] = new_size;
    mem[block_end] = new_size;
    printf("start and end of the block %d %d\n", block_start, block_end);

    // next_end = next + (-mem[next]) + 1;
    // end = next + (-mem[next]) + 2;
    // mem[end] = 0;
    // mem[block_end] = 0;

    // mem[block_start + 1] = mem[next + 1];
    // mem[mem[next+1] + 2] = block_start;
    // mem[block_start + 2] = mem[next + 2];
    // mem[mem[next+2] + 1] = block_start;
    // block_end = next_end;
    // mem[block_start] = new_size;
    // mem[block_end] = new_size; 

  } else if(prev == block_start - 1 && mem[prev] < 0){
    printf("merging from the left side of the hole.\n");
    prev_start = prev + mem[prev] - 1;
    printf("merging holes (%d, %d)\n", prev_start, block_start);
    new_size = mem[block_start] + mem[prev_start] - 2;

    printf("New size of hole is now %d\n", -new_size);
    mem[prev] = 0;
    mem[block_start] = 0;
    mem[block_end] = 0;

    if(head == block_start){
       head = prev_start;
    }

    block_start = prev_start;
    block_end = block_start + (-new_size) + 1;

    printf("start and end of the block %d %d\n", block_start, block_end);
    mem[block_start] = new_size;
    mem[block_end] = new_size;

  } else {

    printf("Now starting search for next and previous pointers for location %d \n", block_start);
    while(mem[next] > 0){
      next = (next + mem[next] + 2) % n;
      if(next == block_start){
        printf("There was no other hole found.\n");
        break;
      }
    }

    if(next != block_start){
      mem[block_start + 1] = mem[next + 1];
      mem[mem[next+1] + 2] = block_start;
      mem[next + 1] = block_start;
      mem[block_start + 2] = next;
    }
  }

    // for(int i = block_start + 3; i < block_end; i++){
    //   mem[i] = 0;
    // }

  // for(int i = block_start; i <= block_end; i++){
  //   printf("%d ", mem[i]);
  // }
  //   printf("\n");

  // for(int i = 0; i < n; i++){
  //   printf("%d ", mem[i]);
  // }
  printf("\n");
  printf("The new hole created is at location %d with previous value %d and next value %d\n", block_start, mem[block_start+1], mem[block_start+2]);
}

void update_memory_utilization(int* blocks, int block_count, int* mem, int n, int x){
  double utilization = 0;
  for(int i = 0;i < block_count;i++){
    utilization += mem[blocks[i]];
    utilization /= n;
    // printf("%f\t",utilization);
    avg_utilization = x != 0 ? avg_utilization + (utilization/x) : avg_utilization + (utilization);
  }
  printf("The average utilization at x = %d is %f\n", x, avg_utilization);
   
}

int main(int argc, char** argv) {
  int x,n,d;
  double v;
  while(*++argv){
    //./main -x 1000 -n 16000000 -d 1000000 -v 256000
    if(**argv != '-')
      return 1;
    switch((*argv)[1]){
      case 'x':
      x = atoi(*++argv);
      break;
      case 'n':
      n = atoi(*++argv);
      break;
      case 'd':
      d = atoi(*++argv);
      break;
      case 'v':
      v = atof(*++argv);
      break;
      default: //error
      return 1;
    }
  }
  int* mem;//the memory
  int* blocks;
  int block_count = 0;
  printf("Running the simulation with x=%d n=%d d=%d v=%.2f\n", x,n,d,v);
  initialize(n, d, v, &mem, &blocks);
  while(x > 0){
    x--;
    while(request(blocks, &block_count, mem, d, v, n));
    update_memory_utilization(blocks, block_count, mem, n, x);
    release(blocks,&block_count,mem, n);
  }
  printf("avg utilization is %.3f", avg_utilization);
  return 0;
}