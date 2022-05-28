/**
 * @file sequence_gen.c
 * @author Clement Bowe(you@domain.com)
 * @brief File to generate sequences for each of the sets
 * @version 0.1
 * @date 2022-05-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define frand() (rand()/(double)RAND_MAX)
#define nrand() (sqrt(-2*log(frand()))*cos(2*M_PI*frand()))




// void initializeRandomSeed() {
//     srand(time(NULL));
// }

void createUniformlyDistributedList(int list[], int size, int min, int max){
  srand(time(NULL));
  for(int i = 0; i < size; i++) {
    list[i] = min + (max-min)*frand();
  }
}


void createNormallyDistributedList(double list[], int size, double mu, double sigma){
  srand(time(NULL));
  for(int i = 0; i < size; i++) {
    list[i] = nrand()*(sigma + mu);
  }
}



void createNormallyRandomDistributedList(double list[], int size, double mu, double sigma, double min, double max){
  srand(time(NULL));
   for(int i = 0; i < size; i++) {
     list[i] = min-1;
     while(list[i] < min || list[i] > max)
         list[i] = nrand()*sigma + mu;
   }
}

void createDivideRandomDistAndNormalDist(double resultList[], double normalDist[], double normalTrunc[], int size){
    srand(time(NULL));
  for(int i = 0; i < size; i++) {
    resultList[i] = normalDist[i]/normalTrunc[i];
  }
}

// I had no idea what to call this
void createSpecialDistributionSequence(double resultList[], int uniform[], double normalDist[], double normalTrunc[], int size) {
    srand(time(NULL));
  for(int i = 0; i < size; i++){
    resultList[i] = 4*uniform[i] - (5* normalDist[i]) + (2 * normalTrunc[i]);
  }
}

