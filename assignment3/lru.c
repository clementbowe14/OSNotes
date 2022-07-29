#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define FRAME_NO 10
#define lrand() rand()*RAND_MAX + rand()
int locate(int* frames, int size, int page_no){
  for(int i = 0; i < size;i++)
    if(frames[i] == page_no)
      return i;
  return -1;
}
int lru(int* ref_str, int size, int limit){
  //size is the # of frames allocated for the process
  //limit is the max # of cells that we look ahead in the RS to implement the LRU algorithm
  //initialize
  int page_faults = size;
  int frames[size], i, cur, page_no, frame_no;
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
  }
  //main loop
  for(;cur < 1000000;cur++){
    page_no = ref_str[cur];
    frame_no = locate(frames, size, page_no);
    if(frame_no != -1)//already exists
      continue;
      
    //look at ref_str[cur+1:cur+limit] to see which one has not been referred to the longest in the future
    page_faults++;
    //This is the very first line that is differnet in other algorithms

    unsigned unused = (1<<size) - 1;
    int victim;
    for(int k = 1; k <= limit && unused && cur - k >= 0;k++){
      victim = locate(frames, size, ref_str[cur - k]);
      if(victim == -1)
        continue;
      unused &= ~(1<<victim);
    }
    if(!unused)
      frames[victim] = page_no;
    else{
      victim = 0;
      while(unused % 2 == 0)
        unused = unused >> 1, victim++;
      frames[victim] = page_no;
    }    
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
  int lru_page_fault = lru(ref_str, FRAME_NO, e * m);
  printf("LRU page replacement causes %d page faults\n", lru_page_fault);
  return 0;
}

