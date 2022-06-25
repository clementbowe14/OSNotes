#include"pa1.h"
#include <math.h>
#include <time.h>
#include "srtheap.h"

#define frand() (rand()/(double)RAND_MAX)
#define nrand() (sqrt(-2*log(frand()))*cos(2*M_PI*frand()))

srtheap generate_arrival_times(int n, int k){
  srtheap h = create_heap(n);
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

  double v = d/4.0;
  //CLA Handling
  printf("CLA Handling!\n");
  srtheap arrival_times = generate_arrival_times(n,k);
  printf("# of processes: %d first 20 arrive times:\n", arrival_times.size);
  srtheap copy = clone(arrival_times);
  for(int i = 0; i < 20;i++)
    printf("%d\t", min_delete(&copy));
  putchar('\n');
  //SJF requires a queue
  lnklst_queue queue = create_queue2();
  int t = 0;//time of my simultor
  double att = 0.0;//keeps track of TTs sum
  process * current = NULL;
  while(!current || t < k || !is_empty2(queue)){
    while(t == peek(&arrival_times)){//new process arrives
      process p;
      p.arrival_time = t;
      p.remaining_time = p.burst_time = (int)round(nrand()*v + d);
      p.tt = 0;
      p.priority_level = rand()%10 + 1;
      enqueue2(&queue, p);
      min_delete(&arrival_times);
      printf("t=%d: a new process admitted, bt = %d\n", t, p.burst_time);
    }
    if(current == NULL && !is_empty2(queue)){
      current = (process*)malloc(sizeof(process));
      *current = dequeue2(&queue);
    }
    if(current != NULL){
      current->remaining_time--;
      if(current->remaining_time == 0){
        current->tt = (t+1) - current->arrival_time;//termination-arrival
        printf("t=%d: a process with arrival time %d and bt %d got terminated with TT = %d\n", t+1, current->arrival_time, current->burst_time, current->tt);
        att += current->tt;        
        free(current);
        current = NULL;
      }
    }
    t++;
  }
  printf("SRT Algorithm for (n,k)=(%d,%d): ATT= %.3f, d= %d, d/ATT= %.3f\n", n, k, att/n, d, d*n/att);

  FILE *fp = fopen("SRT.csv","r");

  if (fp != NULL) {
    fp = fopen("SRT.csv", "a");
    fprintf(fp,"%d, %.3f\n", d, d*n/att);
  } else {
    fp = fopen("SRT.csv", "a");
    fprintf(fp,"d, d/ATT\n");
    fprintf(fp,"%d, %.3f\n", d, d*n/att);
  }
  fclose(fp);

  return 0;
}