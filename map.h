#ifndef map_h
#define map_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

struct  map {
    int size;
    int levelLImit;
    int** gird;         // il sera peut être nécéssaire de faire deux grid
    
};                      // la grid du présent et la grid du futur
typedef struct map map;


int twoPowerRandomPlusonGenerator();
void displayMap(map* map);
map *  mapGridGenerator(map * map, int zone);
map * setConersMap(map * map, int zone);
void mapFreeGrid(map* map);
#endif


