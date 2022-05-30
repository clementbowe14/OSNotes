#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "constants.h"
#include "sequence_gen.h"
#include "avg_std_calculator.h"
#include "histogram.h"


int main()
{
    FILE* f = fopen("data.txt", "w");
    

    int *firstUniformList = malloc(SCENARIO_1_SIZE * sizeof(int));
    int *secondUniformList = malloc(SCENARIO_2_SIZE * sizeof(int));
    int *thirdUniformList = malloc(SCENARIO_3_SIZE * sizeof(int));

    double *firstNormalDistributedList = malloc(SCENARIO_1_SIZE * sizeof(double));
    double *secondNormalDistributedList = malloc(SCENARIO_2_SIZE * sizeof(double));
    double *thirdNormalDistributedList =  malloc(SCENARIO_3_SIZE * sizeof(double));

    double *firstNormalRandomDistributedList = malloc(SCENARIO_1_SIZE * sizeof(double));
    double *secondNormalRandomDistributedList = malloc(SCENARIO_2_SIZE * sizeof(double));
    double *thirdNormalRandomDistributedList = malloc(SCENARIO_3_SIZE * sizeof(double));

    double *firstNormalDistAndRandomDist = malloc(SCENARIO_1_SIZE * sizeof(double));
    double *secondNormalDistAndRandomDist = malloc(SCENARIO_2_SIZE * sizeof(double));
    double *thirdNormalDistAndRandomDist = malloc(SCENARIO_3_SIZE * sizeof(double));

    double *firstSpecialSequence = malloc(SCENARIO_1_SIZE * sizeof(double));
    double *secondSpecialSequence = malloc(SCENARIO_2_SIZE * sizeof(double));
    double *thirdSpecialSequence = malloc(SCENARIO_3_SIZE * sizeof(double));

    const int SCENARIO_MAX_VALUES[] = {8, 2000, 8100};

    createUniformlyDistributedList(firstUniformList, SCENARIO_1_SIZE, SCENARIO_MIN_VALUE, SCENARIO_MAX_VALUES[0]);
    createUniformlyDistributedList(secondUniformList, SCENARIO_2_SIZE, SCENARIO_MIN_VALUE, SCENARIO_MAX_VALUES[1]);
    createUniformlyDistributedList(thirdUniformList, SCENARIO_3_SIZE, SCENARIO_MIN_VALUE, SCENARIO_MAX_VALUES[2]);
    
    
    createNormallyDistributedList(firstNormalDistributedList, SCENARIO_1_SIZE, SCENARIO_1_AVG, SCENARIO_1_STD);
    createNormallyDistributedList(secondNormalDistributedList, SCENARIO_2_SIZE, SCENARIO_2_AVG, SCENARIO_2_STD);
    createNormallyDistributedList(thirdNormalDistributedList, SCENARIO_3_SIZE, SCENARIO_3_AVG, SCENARIO_3_STD);
    
    createNormallyRandomDistributedList(firstNormalRandomDistributedList, SCENARIO_1_SIZE, SCENARIO_1_AVG, 
    SCENARIO_1_STD, SCENARIO_MIN_VALUE, SCENARIO_MAX_VALUES[0]);
    
     createNormallyRandomDistributedList(secondNormalRandomDistributedList, SCENARIO_2_SIZE, SCENARIO_2_AVG, 
                                           SCENARIO_2_STD, SCENARIO_MIN_VALUE, SCENARIO_MAX_VALUES[1]);
    
    createNormallyRandomDistributedList(thirdNormalRandomDistributedList, SCENARIO_3_SIZE, SCENARIO_3_AVG, 
                                           SCENARIO_3_STD, SCENARIO_MIN_VALUE, SCENARIO_MAX_VALUES[2]);
    
    createDivideRandomDistAndNormalDist(firstNormalDistAndRandomDist, firstNormalDistributedList,
                                           firstNormalRandomDistributedList, SCENARIO_1_SIZE);

     createDivideRandomDistAndNormalDist(secondNormalDistAndRandomDist, secondNormalDistributedList, 
                                             secondNormalRandomDistributedList, SCENARIO_2_SIZE);

    createDivideRandomDistAndNormalDist(thirdNormalDistAndRandomDist, thirdNormalDistributedList,
                                          thirdNormalRandomDistributedList, SCENARIO_3_SIZE);

    createSpecialDistributionSequence(firstSpecialSequence, firstUniformList, 
                                           firstNormalDistributedList, firstNormalRandomDistributedList, SCENARIO_1_SIZE);

    createSpecialDistributionSequence(secondSpecialSequence, secondUniformList, 
                                         secondNormalDistributedList, secondNormalRandomDistributedList, SCENARIO_2_SIZE);

    createSpecialDistributionSequence(thirdSpecialSequence, thirdUniformList, 
                                       thirdNormalDistributedList, thirdNormalRandomDistributedList, SCENARIO_3_SIZE);

//averages for all scenarios and sequences
    double uniformAverage1 = calculateAverageWithIntegers(firstUniformList, SCENARIO_1_SIZE);
    double uniformAverage2 = calculateAverageWithIntegers(secondUniformList, SCENARIO_2_SIZE);
    double uniformAverage3 = calculateAverageWithIntegers(thirdUniformList, SCENARIO_3_SIZE);

    double uniformAverages[3] = {uniformAverage1, uniformAverage2, uniformAverage3};

     double normalDistAvg1 = calculateAverage(firstNormalDistributedList, SCENARIO_1_SIZE);
     double normalDistAvg2 = calculateAverage(secondNormalDistributedList, SCENARIO_2_SIZE);
     double normalDistAvg3 = calculateAverage(thirdNormalDistributedList, SCENARIO_3_SIZE);

     double normalDistAverages[3] = {normalDistAvg1, normalDistAvg2, normalDistAvg3};

     double normalRandomAvg1 = calculateAverage(firstNormalDistributedList, SCENARIO_1_SIZE);
     double normalRandomAvg2 = calculateAverage(secondNormalDistributedList, SCENARIO_2_SIZE);
     double normalRandomAvg3 = calculateAverage(thirdNormalDistributedList, SCENARIO_3_SIZE);

     double normalRandomAverages[3] = {normalRandomAvg1, normalRandomAvg2, normalRandomAvg3};

     double normalDistAndRandomAvg1 = calculateAverage(firstNormalDistAndRandomDist, SCENARIO_1_SIZE);
     double normalDistAndRandomAvg2 = calculateAverage(secondNormalDistAndRandomDist, SCENARIO_2_SIZE);
     double normalDistAndRandomAvg3 = calculateAverage(thirdNormalDistAndRandomDist, SCENARIO_3_SIZE);

     double normalDistAndRandomAverages[3] = {normalDistAndRandomAvg1, normalDistAndRandomAvg2, normalDistAndRandomAvg3};

     double specialAvg1 = calculateAverage(firstSpecialSequence, SCENARIO_1_SIZE);
     double specialAvg2 = calculateAverage(secondSpecialSequence, SCENARIO_2_SIZE);
     double specialAvg3 = calculateAverage(thirdSpecialSequence, SCENARIO_3_SIZE);

     double specialSequenceAverages[3] = {specialAvg1, specialAvg2, specialAvg3};


// std for all scenarios and sequences

    double uniformStd1 = calculateStandardDeviationWithIntegers(firstUniformList, SCENARIO_1_SIZE, uniformAverages[0]);
    double uniformStd2 = calculateStandardDeviationWithIntegers(secondUniformList, SCENARIO_2_SIZE, uniformAverages[1]);
    double uniformStd3 = calculateStandardDeviationWithIntegers(thirdUniformList, SCENARIO_3_SIZE, uniformAverages[2]);

    double uniformStds[3] = {uniformStd1, uniformStd2, uniformStd3};

     double normalDistStd1 = calculateStandardDeviation(firstNormalDistributedList, SCENARIO_1_SIZE, normalDistAverages[0]);
     double normalDistStd2 = calculateStandardDeviation(secondNormalDistributedList, SCENARIO_2_SIZE, normalDistAverages[1]);
     double normalDistStd3 = calculateStandardDeviation(thirdNormalDistributedList, SCENARIO_3_SIZE, normalDistAverages[2]);

     double normalDistStds[3] = {normalDistStd1, normalDistStd2, normalDistStd3};

     double normalRandomStd1 = calculateStandardDeviation(firstNormalDistributedList, SCENARIO_1_SIZE, normalRandomAverages[0]);
     double normalRandomStd2 = calculateStandardDeviation(secondNormalDistributedList, SCENARIO_2_SIZE, normalRandomAverages[1]);
     double normalRandomStd3 = calculateStandardDeviation(thirdNormalDistributedList, SCENARIO_3_SIZE, normalRandomAverages[2]);

     double normalRandomStds[3] = {normalRandomStd1, normalRandomStd2, normalRandomStd3};

    double normalDistAndRandomStd1 = calculateStandardDeviation(firstNormalDistAndRandomDist, SCENARIO_1_SIZE, normalDistAndRandomAverages[0]);
    double normalDistAndRandomStd2 = calculateStandardDeviation(secondNormalDistAndRandomDist, SCENARIO_2_SIZE, normalDistAndRandomAverages[1]);
    double normalDistAndRandomStd3 = calculateStandardDeviation(thirdNormalDistAndRandomDist, SCENARIO_3_SIZE, normalDistAndRandomAverages[2]);

    double normalDistAndRandomStds[3] = {normalDistAndRandomStd1, normalDistAndRandomStd2, normalDistAndRandomStd3};

    double specialSequenceStd1 = calculateStandardDeviation(firstSpecialSequence, SCENARIO_1_SIZE, normalDistAndRandomAverages[0]);
    double specialSequenceStd2 = calculateStandardDeviation(secondNormalDistAndRandomDist, SCENARIO_2_SIZE, normalDistAndRandomAverages[1]);
    double specialSequenceStd3 = calculateStandardDeviation(thirdNormalDistAndRandomDist, SCENARIO_3_SIZE, normalDistAndRandomAverages[2]);

    double specialSequenceStds[3] = {specialSequenceStd1, specialSequenceStd2, specialSequenceStd3};
    fprintf(f, "%s", "UNIFORM DISTRIBUTED AVERAGES AND STANDARD DEVIATION\n\n");
    fprintf(f, "%s", "AVERAGES\n");

    for(int i = 0; i < 3; i++) {
       fprintf(f, "%f\t", uniformAverages[i]);
     }

    fprintf(f, "%s", "\n");

    fprintf(f, "%s", "STANDARD DEVIATION\n");



    for(int i = 0; i < 3; i++) {
      fprintf(f, "%f\t", uniformStds[i]); 
    }

  fprintf(f, "%s", "\n\nNORMAL DISTRIBUTED AVERAGES AND STANDARD DEVIATION\n\n");

     for(int i = 0; i < 3; i++) {
       fprintf(f, "%f\t", normalDistAverages[i]);
    }
    
    fprintf(f, "%s", "\n");

     for(int i = 0; i < 3; i++) {
           fprintf(f, "%f\t", normalDistStds[i]);
       }
  
  fprintf(f, "%s", "\n\nNORMAL DISTRIBUTED RANDOM AVERAGES AND STANDARD DEVIATION\n\n");

  fprintf(f, "%s", "AVERAGES\n");
      for(int i = 0; i < 3; i++) {
         fprintf(f,"%f\t", normalRandomAverages[i]);
       }
      
          fprintf(f, "%s", "\n");

  fprintf(f, "%s", "STANDARD DEVIATION\n");


  for(int i = 0; i < 3; i++) {
    fprintf(f, "%f\t", normalRandomAverages[i]);
  }

  fprintf(f, "%s", "\n\nNORMAL DISTRIBUTED/ NORMAL RANDOM AVERAGES AND STANDARD DEVIATION\n\n");
    
  fprintf(f, "%s", "AVERAGES\n");

  for(int i = 0; i < 3; i++) {
       fprintf(f,"%f\t", normalDistAndRandomAverages[i]);
     }
    fprintf(f, "%s", "\n");

  fprintf(f, "%s", "STANDARD DEVIATION\n");


     for(int i = 0; i < 3; i++) {
       fprintf(f, "%f\t", normalDistAndRandomStds[i]);
     }


  fprintf(f, "%s", "\n\nSPECIAL SEQUENCE AVERAGES AND STANDARD DEVIATION\n\n");

    fprintf(f, "%s", "AVERAGES\n");


  for(int i = 0; i < 3; i++) {
    fprintf(f,"%f\t", specialSequenceAverages[i]);
  }
    
  fprintf(f, "%s", "\n");

  fprintf(f, "%s", "STANDARD DEVIATION\n");

  for(int i = 0; i < 3; i++) {
    fprintf(f, "%f\t", specialSequenceStds[i]);
  }

  fclose(f);
  
  FILE* normalRandomDistributionHistogram = fopen("normalrandomhist.csv", "w");
  FILE* normalDistributionDivideNormalRandomHistogram = fopen("normaldistdividenormalrandom.csv", "w");
  FILE* specialDistributionHistogram = fopen("specialDistributionHistogram.csv", "w");
  FILE* normalDistributionHistogram = fopen("normalhist.csv", "w");
  FILE* uniformHistogram = fopen("uniformhist.csv", "w");

if(uniformHistogram != NULL){
  createHistogramIntegers(thirdUniformList, SCENARIO_3_SIZE, SCENARIO_MIN_VALUE, SCENARIO_MAX_VALUES[2], uniformHistogram);
  printf("%s\n", "Uniform Histogram Complete");
}


if(normalDistributionHistogram != NULL){
     createHistogramRealNumbers(thirdNormalDistributedList, SCENARIO_3_SIZE, SCENARIO_MIN_VALUE, SCENARIO_MAX_VALUES[2], normalDistributionHistogram);
     printf("%s\n", "Normal Distribution Histogram Complete");
   }

if(normalRandomDistributionHistogram != NULL){
  createHistogramRealNumbers(thirdNormalDistAndRandomDist, SCENARIO_3_SIZE, SCENARIO_MIN_VALUE, SCENARIO_MAX_VALUES[2], normalDistributionDivideNormalRandomHistogram);
  printf("%s\n", "Normal Distribution / Normal Random Distribution Histogram Complete");
  }


if(normalDistributionDivideNormalRandomHistogram != NULL){
  createHistogramRealNumbers(thirdNormalRandomDistributedList, SCENARIO_3_SIZE, SCENARIO_MIN_VALUE, SCENARIO_MAX_VALUES[2], normalRandomDistributionHistogram);
  printf("%s\n", "Normal Distribution Histogram Complete");
  }

if(specialDistributionHistogram != NULL){
    createHistogramRealNumbers(thirdSpecialSequence, SCENARIO_3_SIZE, SCENARIO_MIN_VALUE, SCENARIO_MAX_VALUES[2], specialDistributionHistogram);
    printf("%s\n", "Special Distribution Histogram Complete");

}

  fclose(uniformHistogram);
  fclose(normalDistributionHistogram);
  fclose(normalRandomDistributionHistogram);
  fclose(normalDistributionDivideNormalRandomHistogram);
  fclose(specialDistributionHistogram);

    return 0;
}
