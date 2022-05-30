#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define N_BINS 100


void createHistogramIntegers(int list[], int size, double min, double max, FILE* f){
    
    int *histogram = malloc(N_BINS * sizeof(int));
    for(int i = 0; i < N_BINS;i++)
        histogram[i] = 0;
    
    for(int i = 0; i < size; i++){
        int col = (int)floor((list[i]*N_BINS)/(max-min));
         histogram[col]++;
    }


    for(int i = 0; i < N_BINS;i++){
        fprintf(f, "%d\n", histogram[i]);
    }

    free(histogram);

}


void createHistogramRealNumbers(double list[], int size, int min, double max, FILE* f){

    
    int *histogram= malloc(N_BINS * sizeof(int));
    for(int i = 0; i < N_BINS;i++)
        histogram[i] = 0;
    
    for(int i = 0; i < size; i++){
        int col = (int)floor((list[i]*N_BINS)/(max-min));
        if(col < 0)
            continue;
         histogram[col]++;
    }

    for(int i = 0; i < N_BINS;i++){
        fprintf(f, "%d\n", histogram[i]);
    }

    free(histogram);
    printf("%s\n", "finished writing to file");
}

void writeDataToFile_I(int list[], int size, FILE* f){
   for(int i = 0; i < size;i++){
        fprintf(f, "%d\n", list[i]);
    }
}

void writeDataToFile_F(double list[], int size, FILE* f){
   for(int i = 0; i < size;i++){
        fprintf(f, "%f\n", list[i]);
    }
}