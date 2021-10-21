#ifndef map_h
#define map_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

struct  Map {
    int* size;
    int* levelLImit;
    int** gird;         // il sera peut être nécéssaire de faire deux grid
    
};                      // la grid du présent et la grid du futur
typedef struct Map Map;

Map *  genMapForTest();
int twoPowerRandomPlusonGenerator();
void displayMap(Map* wolrd);
int genMapSize();
Map * mapGridGenerator(int zone);
Map * setConersMap(Map* m, int zone);
void mapFreeGrid(Map* wolrd);
#endif


