#include <stdlib.h>
#include <stdio.h>
#include "process.h"
#include "srtheap.h"
#include "utils.h"
#include "process_queue.h"


int main(int argc, char *argv[]) {

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

  int nk[4][2] = {{100,1000 },{500,10000},{500,5000},{1000,10000}};

  //CLA Handling
  FILE* fp;
for(int i = 0; i < 4; i++){
 
  if(i == 0){
    fp = fopen("SRT1.csv", "w");
  } else if(i == 1){
    fp = fopen("SRT2.csv", "w");
  }else if(i == 2){
    fp = fopen("SRT3.csv", "w");
  }  else {
    fp = fopen("SRT4.csv", "w");
  }
  n = nk[i][0];
  k = nk[i][1];
  fprintf(fp,"d, d/ATT\n");

  for(d = k/n; d <= 25*(k/n); d += k/n){



    int * totalCPUTimes= malloc(n * sizeof(int));
    int * arrivalTimes = malloc(n * sizeof(int));
    ProcessNode* nodes = malloc(n * sizeof(struct ProcessNode));
    ProcessQueue newNodes = createProcessQueue();
    ProcessQueue terminatedNodes = createProcessQueue();
    srtheap scheduler = create_heap(n);
    double v = d/4;



      //uniform distribution of arrival times

    createUniformlyDistributedList(arrivalTimes, n, 0, k);
    printf("created arrival times for the processes\n");

    //normal distribution of total cpu time
    createNormallyDistributedList(totalCPUTimes, n, d, v);
    printf("created cpu times times for the processes%s\n", "");

    for(int i = 0; i < n; i++) {
        createNode(&nodes[i], i+1, arrivalTimes[i], 0, totalCPUTimes[i], totalCPUTimes[i], 1, 1);
    }
    printf("created process data structures %s\n", "");
    
    sortProcesses(nodes, n);

    for(int i = 0; i < n; i++){
      printf("pid: %d\t arrivalTime: %d\t totalCPUTime: %d\t\n", nodes[i].pid, nodes[i].arrivalTime, nodes[i].totalCpuTime);
    }

    printf("adding nodes to newNode queue\n");
    for(int i = 0; i < n; i++){
        enqueue(&newNodes, &nodes[i]);
    }
    printf("nodes added\n");
    double attime = 0;
    double terminated = 0;
    int time = 0;

    while(terminated < n){
      
      while(!isEmpty(newNodes) && front(&newNodes)->arrivalTime <= time){
            printf("insert node into scheduler\n");
            min_insert(&scheduler, front(&newNodes));
            dequeue(&newNodes);
        }
      
      if(!is_empty(scheduler)){
          ProcessNode* node = peek(&scheduler);
          node->remainingTime--;
          if(node->remainingTime == 0){
              delete(&scheduler);
              int tt = (time+1) - node->arrivalTime;//termination-arrival
              printf("t=%d: a process with arrival time %d and bt %d got terminated with TT = %d\n", time+1, node->arrivalTime, node->totalCpuTime, tt);
              attime += tt;  
              terminated++;
          }
      }

      time++;
    }
  
  printf("SJF Algorithm for (n,k)=(%d,%d): ATT= %.3f, d= %d, d/ATT= %.3f\n", n, k, attime/n, d, d*n/attime);
  fprintf(fp,"%d, %.3f\n", d, d*n/attime);

  }
  fclose(fp);
}

}