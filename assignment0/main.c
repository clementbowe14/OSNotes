#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "constants.h"
#include "sequence_gen.h"
#include "avg_std_calculator.h"

// #define frand() (rand()/(double)RAND_MAX)
// #define nrand() (sqrt(-2*log(frand()))*cos(2*M_PI*frand()))

int main()//-m 9 -M 11 -mu 10 -sigma 1 -n 20 -name data1.txt
{
    FILE* f = fopen("data.txt", "w");

    int *firstUniformList = malloc(SCENARIO_1_SIZE * sizeof(int));
    int *secondUniformList = malloc(SCENARIO_2_SIZE * sizeof(int));
    int *thirdUniformList = malloc(SCENARIO_3_SIZE * sizeof(int));

    double *firstNormalDistributedList = (double *)malloc(SCENARIO_1_SIZE);
    double *secondNormalDistributedList = (double *)malloc(SCENARIO_2_SIZE);
    double *thirdNormalDistributedList = (double *)malloc(SCENARIO_3_SIZE);

    double *firstNormalRandomDistributedList =(double *)malloc(SCENARIO_1_SIZE);
    double *secondNormalRandomDistributedList = (double *)malloc(SCENARIO_2_SIZE);
    double *thirdNormalRandomDistributedList = (double *)malloc(SCENARIO_3_SIZE);

    double *firstNormalDistAndRandomDist =(double *)malloc(SCENARIO_1_SIZE);
    double *secondNormalDistAndRandomDist = (double *)malloc(SCENARIO_2_SIZE);
    double *thirdNormalDistAndRandomDist = (double *)malloc(SCENARIO_3_SIZE);

    double *firstSpecialSequence =(double *)malloc(SCENARIO_1_SIZE);
    double *secondSpecialSequence = (double *)malloc(SCENARIO_2_SIZE);
    double *thirdSpecialSequence = (double *)malloc(SCENARIO_3_SIZE);

    const int SCENARIO_MAX_VALUES[] = {8, 2000, 8100};

    
    //initializeRandomSeed();
    
    createUniformlyDistributedList(firstUniformList, SCENARIO_1_SIZE, SCENARIO_MIN_VALUE, SCENARIO_MAX_VALUES[0]);
    createUniformlyDistributedList(secondUniformList, SCENARIO_2_SIZE, SCENARIO_MIN_VALUE, SCENARIO_MAX_VALUES[1]);
    createUniformlyDistributedList(thirdUniformList, SCENARIO_3_SIZE, SCENARIO_MIN_VALUE, SCENARIO_MAX_VALUES[2]);
    
    double uniformAverage1 = calculateAverageWithIntegers(firstUniformList, SCENARIO_1_SIZE);
    double uniformAverage2 = calculateAverageWithIntegers(secondUniformList, SCENARIO_2_SIZE);
    double uniformAverage3 = calculateAverageWithIntegers(thirdUniformList, SCENARIO_3_SIZE);
    double uniformAverages[3] = {uniformAverage1, uniformAverage2, uniformAverage3};

    double uniformStd1 = calculateStandardDeviationWithIntegers(firstUniformList, SCENARIO_1_SIZE, uniformAverages[0]);
    double uniformStd2 = calculateStandardDeviationWithIntegers(secondUniformList, SCENARIO_2_SIZE, uniformAverages[1]);
    double uniformStd3 = calculateStandardDeviationWithIntegers(thirdUniformList, SCENARIO_3_SIZE, uniformAverages[2]);

    double uniformStds[3] = {uniformStd1, uniformStd2, uniformStd3};


    for(int i = 0; i < 3; i++) {
       fprintf(f, "%f\t", uniformAverages[i]);
     }

         for(int i = 0; i < 3; i++) {
           fprintf(f, "%f\t", uniformStds[i]);
       }

      free(firstUniformList);
      free(secondUniformList);
      free(thirdUniformList);



    
    createNormallyDistributedList(firstNormalDistributedList, SCENARIO_1_SIZE, SCENARIO_1_AVG, SCENARIO_1_STD);
    createNormallyDistributedList(secondNormalDistributedList, SCENARIO_2_SIZE, SCENARIO_2_AVG, SCENARIO_2_STD);
    createNormallyDistributedList(thirdNormalDistributedList, SCENARIO_3_SIZE, SCENARIO_3_AVG, SCENARIO_3_STD);
    
    // createNormallyRandomDistributedList(firstNormalRandomDistributedList, SCENARIO_1_SIZE, SCENARIO_1_AVG, SCENARIO_1_STD, SCENARIO_MIN_VALUE, SCENARIO_MAX_VALUES[0]);
    
    // createNormallyRandomDistributedList(secondNormalRandomDistributedList, SCENARIO_2_SIZE, SCENARIO_2_AVG, 
    //                                       SCENARIO_2_STD, SCENARIO_MIN_VALUE, SCENARIO_MAX_VALUES[1]);
    
    // createNormallyRandomDistributedList(thirdNormalRandomDistributedList, SCENARIO_3_SIZE, SCENARIO_3_AVG, 
    //                                       SCENARIO_3_STD, SCENARIO_MIN_VALUE, SCENARIO_MAX_VALUES[2]);
    
    // createDivideRandomDistAndNormalDist(firstNormalDistAndRandomDist, firstNormalDistributedList,
    //                                       firstNormalRandomDistributedList, SCENARIO_1_SIZE);

    // createDivideRandomDistAndNormalDist(secondNormalDistAndRandomDist, secondNormalDistributedList, 
    //                                         secondNormalRandomDistributedList, SCENARIO_2_SIZE);

    // createDivideRandomDistAndNormalDist(thirdNormalDistAndRandomDist, thirdNormalDistributedList,
    //                                      thirdNormalRandomDistributedList, SCENARIO_3_SIZE);

    // createSpecialDistributionSequence(firstSpecialSequence, firstUniformList, 
    //                                       firstNormalDistributedList, firstNormalRandomDistributedList, SCENARIO_1_SIZE);

    // createSpecialDistributionSequence(secondSpecialSequence, secondUniformList, 
    //                                     secondNormalDistributedList, secondNormalRandomDistributedList, SCENARIO_2_SIZE);

    // createSpecialDistributionSequence(thirdSpecialSequence, thirdUniformList, 
    //                                   thirdNormalDistributedList, thirdNormalRandomDistributedList, SCENARIO_3_SIZE);

// averages for all scenarios and sequences
     // double uniformAverage1 = calculateAverageWithIntegers(firstUniformList, SCENARIO_1_SIZE);
    // double uniformAverage2 = calculateAverageWithIntegers(secondUniformList, SCENARIO_2_SIZE);
    // double uniformAverage3 = calculateAverageWithIntegers(thirdUniformList, SCENARIO_3_SIZE);

    // double uniformAverages[3] = {uniformAverage1, uniformAverage2, uniformAverage3};

    // double normalDistAvg1 = calculateAverage(firstNormalDistributedList, SCENARIO_1_SIZE);
    // double normalDistAvg2 = calculateAverage(secondNormalDistributedList, SCENARIO_2_SIZE);
    // double normalDistAvg3 = calculateAverage(thirdNormalDistributedList, SCENARIO_3_SIZE);

    // double normalDistAverages[3] = {normalDistAvg1, normalDistAvg2, normalDistAvg3};

    // double normalRandomAvg1 = calculateAverage(firstNormalDistributedList, SCENARIO_1_SIZE);
    // double normalRandomAvg2 = calculateAverage(secondNormalDistributedList, SCENARIO_2_SIZE);
    // double normalRandomAvg3 = calculateAverage(thirdNormalDistributedList, SCENARIO_3_SIZE);

    // double normalRandomAverages[3] = {normalRandomAvg1, normalRandomAvg2, normalRandomAvg3};

    // double normalDistAndRandomAvg1 = calculateAverage(firstNormalDistAndRandomDist, SCENARIO_1_SIZE);
    // double normalDistAndRandomAvg2 = calculateAverage(secondNormalDistAndRandomDist, SCENARIO_2_SIZE);
    // double normalDistAndRandomAvg3 = calculateAverage(thirdNormalDistAndRandomDist, SCENARIO_3_SIZE);

    // double normalDistAndRandomAverages[3] = {normalDistAndRandomAvg1, normalDistAndRandomAvg2, normalDistAndRandomAvg3};

    // double specialAvg1 = calculateAverage(firstSpecialSequence, SCENARIO_1_SIZE);
    // double specialAvg2 = calculateAverage(secondSpecialSequence, SCENARIO_2_SIZE);
    // double specialAvg3 = calculateAverage(thirdSpecialSequence, SCENARIO_3_SIZE);

    // double specialSequenceAverages[3] = {specialAvg1, specialAvg2, specialAvg3};


// std for all scenarios and sequences

    // double uniformStd1 = calculateStandardDeviationWithIntegers(firstUniformList, SCENARIO_1_SIZE, uniformAverages[0]);
    // double uniformStd2 = calculateStandardDeviationWithIntegers(secondUniformList, SCENARIO_2_SIZE, uniformAverages[1]);
    // double uniformStd3 = calculateStandardDeviationWithIntegers(thirdUniformList, SCENARIO_3_SIZE, uniformAverages[2]);

    // double uniformStds[3] = {uniformStd1, uniformStd2, uniformStd3};

    // double normalDistStd1 = calculateStandardDeviation(firstNormalDistributedList, SCENARIO_1_SIZE, normalDistAverages[0]);
    // double normalDistStd2 = calculateStandardDeviation(secondNormalDistributedList, SCENARIO_2_SIZE, normalDistAverages[1]);
    // double normalDistStd3 = calculateStandardDeviation(thirdNormalDistributedList, SCENARIO_3_SIZE, normalDistAverages[2]);

    // double normalDistStds[3] = {normalDistStd1, normalDistStd2, normalDistStd3};

    // double normalRandomStd1 = calculateStandardDeviation(firstNormalDistributedList, SCENARIO_1_SIZE, normalRandomAverages[0]);
    // double normalRandomStd2 = calculateStandardDeviation(secondNormalDistributedList, SCENARIO_2_SIZE, normalRandomAverages[1]);
    // double normalRandomStd3 = calculateStandardDeviation(thirdNormalDistributedList, SCENARIO_3_SIZE, normalRandomAverages[2]);

    // double normalRandomStds[3] = {normalRandomStd1, normalRandomStd2, normalRandomStd3};

    // double normalDistAndRandomStd1 = calculateStandardDeviation(firstNormalDistAndRandomDist, SCENARIO_1_SIZE, normalDistAndRandomAverages[0]);
    // double normalDistAndRandomStd2 = calculateStandardDeviation(secondNormalDistAndRandomDist, SCENARIO_2_SIZE, normalDistAndRandomAverages[1]);
    // double normalDistAndRandomStd3 = calculateStandardDeviation(thirdNormalDistAndRandomDist, SCENARIO_3_SIZE, normalDistAndRandomAverages[2]);

    // double normalDistAndRandomStds[3] = {normalDistAndRandomStd1, normalDistAndRandomStd2, normalDistAndRandomStd3};

    // double specialSequenceStd1 = calculateStandardDeviation(firstSpecialSequence, SCENARIO_1_SIZE, normalDistAndRandomAverages[0]);
    // double specialSequenceStd2 = calculateStandardDeviation(secondNormalDistAndRandomDist, SCENARIO_2_SIZE, normalDistAndRandomAverages[1]);
    // double specialSequenceStd3 = calculateStandardDeviation(thirdNormalDistAndRandomDist, SCENARIO_3_SIZE, normalDistAndRandomAverages[2]);

    // double specialSequenceStds[3] = {specialSequenceStd1, specialSequenceStd2, specialSequenceStd3};


    // for(int i = 0; i < 3; i++) {
    //   fprintf(f, "%f\t", normalDistAverages[i]);
    // }

    // for(int i = 0; i < 3; i++) {
    //       fprintf(f, "%f\t", normalDistStds[i]);
    //   }


    //   for(int i = 0; i < 3; i++) {
    //     fprintf(f,"%f\t", normalRandomAverages[i]);
    //   }


    // for(int i = 0; i < 3; i++) {
    //       fprintf(f, "%f\t", normalRandomAverages[i]);
    //   }
    

    // for(int i = 0; i < 3; i++) {
    //   fprintf(f,"%f\t", normalDistAndRandomAverages[i]);
    // }
    


    // for(int i = 0; i < 3; i++) {
    //   fprintf(f, "%f\t", normalDistAndRandomStds[i]);
    // }

    // for(int i = 0; i < 3; i++) {
    //   fprintf(f,"%f\t", specialSequenceAverages[i]);
    // }
    

    // for(int i = 0; i < 3; i++) {
    //   fprintf(f, "%f\t", specialSequenceStds[i]);
    // }

    // fclose(f);


  // FILE* f = fopen("data1.csv", "w");

  // fprintf(f, "s1\ts2\ts3\ts4\ts5\n");

  // for(int i = 0; i < 20;i++){

  //   int s1;
  //   double s2;
  //   int s3;
  //   double s4, s5;
  //   //generate all of them

  //    s3 = (int)(M-m)*frand();
    
  //   fprintf(f, "%d\t%.2f\t%d\t%.2f\t%.2f\n",s1,s2,s3,s4,s5);
  // }
  // fclose(f);
    return 0;
}
