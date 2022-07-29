#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "pa3.h"

#define FRAME_NO 10
#define lrand() rand()*RAND_MAX + rand()
int locate(int* frames, int size, int page_no){
  for(int i = 0; i < size;i++)
    if(frames[i] == page_no)
      return i;
  return -1;
}


struct node* front = NULL;
struct node* rear = NULL;

void enqueue2(int val)
{
  struct node* ptr;
  ptr = (struct node*)malloc(sizeof (struct node));
  ptr -> value = val;
  ptr -> next = NULL;
  
  if ((front == NULL) && (rear == NULL)) {
    front = rear = ptr;
  } else {
    rear -> next = ptr;
    rear = ptr;
  }
}

int dequeue2() {
  if(front == NULL) {
    printf("UNDER!!");
    return -1;
  } else {
    struct node* temp = front;
    int temp_val = temp->value;
    front = front->next;
    free(temp);
    return temp_val;
  }
}

int second(int* ref_str, int size, int limit){
  //size is the # of frames allocated for the process
  //limit is the max # of cells that we look ahead in the RS to implement the optimal algorithm
  //initialize
  int page_faults = size;
  int frames[FRAME_NO], i, cur, page_no, frame_no;
  int *mod = (int*)malloc(size*sizeof(int));

  for(i = 0; i < size;i++)
    frames[i] = -1;//empty
  for(i = 0, cur = 0; i < size;i++,cur++){
    //filling out the whole physical memory (frames array)
    page_no = ref_str[cur];
    frame_no = locate(frames,size, page_no);
    if(frame_no + 1)//already exists
      i--;
    else
      frames[i] = page_no;
      mod[i] = 1;
      enqueue2(i);
  }
  //main loop
  for(;cur < 1000000;cur++){
    page_no = ref_str[cur];
    frame_no = locate(frames, size, page_no);
    if(frame_no != -1)//already exists
      continue;
    
    int index = dequeue2();
    while(mod[index] == 1){
      printf("getting second chance");
      mod[index]--;
      enqueue2(index);
      index = dequeue2();
    }

    page_faults++;
    frames[index] = page_no;
    mod[index] = 1;
    enqueue2(index);
  } 
  return page_faults;
}


int main(int argc, char** argv) {
  int e, m, P;
  double t;
  srand(time(NULL));
  while(*++argv){
    //./main -P 1048576 -e 10 -m 20 -t 1000 (Scenario #1)
    if(**argv != '-')
      return 1;
    switch((*argv)[1]){
      case 'P':
      P = atoi(*++argv);
      break;
      case 'e':
      e = atoi(*++argv);
      break;
      case 'm':
      m = atoi(*++argv);
      break;
      case 't':
      t = 1.0/atoi(*++argv);
      break;
      default: //error
      return 1;
    }
  }
  printf("CLAs are P = %d, locus size = %d, m = %d, transition prob. = %f\n", P, e, m, t);
  //initially locus: 0...e-1
  int locus_position = 0;//s
  int ref_count = 0;
  int*ref_str = (int*) malloc(1000000*sizeof(int));
  while(ref_count <= 1000000){
    int next_ref = rand()%e + locus_position;
    if(!ref_count || next_ref != ref_str[ref_count-1])
      ref_str[ref_count++] = next_ref;
    else//try again
      continue;
    if(ref_count%m == 0){//let's displace the locus
      if(rand() < t * RAND_MAX)//jump
        locus_position = lrand()%(P-e+1);
      else
        locus_position = (locus_position + 1)%(P-e+1);
    }
  }
  int second_page_fault = second(ref_str, FRAME_NO, e * m);
  printf("Second page replacement causes %d page faults\n", second_page_fault);
  return 0;
}

