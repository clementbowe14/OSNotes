#include <math.h>
#include <time.h>
#include "sjfheap.h"

#define frand() (rand()/(double)RAND_MAX)
#define nrand() (sqrt(-2*log(frand()))*cos(2*M_PI*frand()))
sjfheap generate_arrival_times(int n, int k){
  sjfheap h = create_heap(n);
  for(int i = 0; i < n;i++)
    min_insert(&h, frand()*k);
  return h;
}

int main(int argc, char** argv) {
   srand(time(NULL));
  int n = 100;
  int k = 1000;
  int d = k/n;
  while(*++argv){
    if(**argv == '-' && (*argv)[1] == 'n')
      n = atoi(*++argv);
    else if(**argv == '-' && (*argv)[1] == 'k')
      k = atoi(*++argv);
    else if(**argv == '-' && (*argv)[1] == 'd')
      d = atoi(*++argv);
    else
      continue;
  }