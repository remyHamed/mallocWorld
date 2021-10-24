#ifndef map_h
#define map_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "player.h"

struct  Map {
    int* size;
    int* levelLImit;
    int** gird;         // il sera peut être nécéssaire de faire deux grid
    
};                      // la grid du présent et la grid du futur
typedef struct Map Map;

int twoPowerRandomPlusonGenerator();
int genMapSize();
Map * setConersMap(Map* m, int zone);
int randMaxOrRandMin(int min, int max);


#endif


