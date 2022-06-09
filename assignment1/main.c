#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
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


void createNormallyDistributedList(double list[], int size, double mu, double sigma){
  srand(time(NULL));
  for(int i = 0; i < size; i++) {
    list[i] = 0;
  }
  for(int i = 0; i < size; i++) {
    list[i] = (nrand()*sigma) + mu;
    }

}
int main(int argc, char *argv[]) {

    printf("number of args, %d\n", argc);
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    int d = atoi(argv[3]);
    int v = atoi(argv[4]);

    printf("n%d\nk%d\n d %d\n v %d\n", n, k, d, v);
    int * totalCPUTimes = malloc(n * sizeof(int));
    createUniformlyDistributedList(totalCPUTimes, n, d, v);

    for(int i = 0; i < n; i++) {
        printf("Total CPU time of process %d is: %d \n", i, totalCPUTimes[i]);
    }
    
}