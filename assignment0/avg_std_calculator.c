#include <math.h>
#include <stdlib.h>


double calculateAverageWithIntegers(int list[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += list[i];
    }

    return sum/size;
}


double calculateAverage(double list[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += list[i];
    }

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
