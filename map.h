#ifndef map_h
#define map_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

struct  map {
    int height;
    int width;
    int levelLImit;
    int** gird;         // il sera peut être nécéssaire de faire deux grid
};                      // la grid du présent et la grid du futur
typedef struct map map;

void displayMap(map* map);
void mapGridGenerator(map* map);
void mapFreeGrid(map* map);
#endif


