#ifndef fmap_h
#define fmap_h
#include <stdlib.h>
#include "arr2d.h"
#include "rng.h"
#include "gate.h"
#include "fgate.h"
Map * initMap();
Map * initMapSaved(int size);
Map ** initListOfMaps();
Map ** genAllLevels();
Map ** genAllLevelsSaved(int * size);
int isOutofBound(Map* m, int* arr);
#endif