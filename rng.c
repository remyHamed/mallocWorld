#include "headers/rng.h"

int twoPowerRandomPlusonGenerator() {
    struct timespec tv;
    clock_gettime(CLOCK_REALTIME, &tv);
    int t =tv.tv_nsec; 
    srand(t);
    int min = 7;
    int max = 11;
    int mapSize = rand() % (max - min + 1) + min; 
    return mapSize;
}

int genrandomSizeMap() {
    return pow(2,twoPowerRandomPlusonGenerator()) + 1;
}