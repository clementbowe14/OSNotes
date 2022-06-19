#include <process.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#define frand() (rand()/(double)RAND_MAX)
#define nrand() (sqrt(-2*log(frand()))*cos(2*M_PI*frand()))

void createUniformlyDistributedList(int list[], int size, double min, double max){
  srand(time(NULL));
    for(int i = 0; i < size; i++) {
    list[i] = 0;
  }
  for(int i = 0; i < size; i++) {
    int range = (max-min);
    list[i] = (frand() * range) + min;
  }
 
}

void createNormallyDistributedList(int list[], int size, double mu, double sigma){
  srand(time(NULL));
  for(int i = 0; i < size; i++) {
    list[i] = 0;
  }
  for(int i = 0; i < size; i++) {
    list[i] = (nrand()*sigma) + mu;
    }

}

void sortProcesses(ProcessNode* nodes, int size){
  printf("Begin sorting the processes %s\n", "");
  for(int i = 0; i < size-1; i++){
    int min = i;
    for(int j = i+1; j < size; j++){
      if(nodes[j].arrivalTime < nodes[min].arrivalTime){
        min = j;
      }
    }
    if(min != i){
      ProcessNode temp = nodes[i];
      nodes[i] = nodes[min];
      nodes[min] = temp;
    }
  }
  printf("Finished sorting the array %s\n", "");
}