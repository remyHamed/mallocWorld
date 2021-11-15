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

int * genrandomPosition(int mapSize) {
    int x = (mapSize / 2) * twoPowerRandomPlusonGenerator();
    int y = (mapSize / 2) * twoPowerRandomPlusonGenerator();
    int * arr = malloc(sizeof(int) * 2);
    while (x > mapSize || x < 0) {
        if(x < 0) {
            x  = x + twoPowerRandomPlusonGenerator(); 
        } else {
            x  = x - twoPowerRandomPlusonGenerator();
        }
    }
    while (y > mapSize || y < 0) {
        if(y < 0) {
            y  = y + twoPowerRandomPlusonGenerator(); 
        } else {
            y  = y - twoPowerRandomPlusonGenerator();
        }
    }
    arr[0] = x;
    arr[1] = y;
    return arr;
}