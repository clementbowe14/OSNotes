#include <math.h>
#include <stdlib.h>
#include <stdio.h>

double calculateAverageWithIntegers(int list[], int size) {
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum += list[i];
    }

    // printf("%f\n", sum/size);

    return sum/size;
}


double calculateAverage(double list[], int size) {
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum += list[i];
    }
    // printf("%f\n", sum);

    return sum/size;
}


double calculateStandardDeviationWithIntegers(int list[], int size, double avg) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += (list[i]-avg) * (list[i]-avg);
    }

    return sqrt(sum/size-1);
}



double calculateStandardDeviation(double list[], int size, double avg) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += (list[i]-avg) * (list[i]-avg);
    }

    return sqrt(sum/size-1);
}
