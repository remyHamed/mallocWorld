#ifndef fmap_h
#define fmap_h
#include <stdlib.h>
#include "arr2d.h"
#include "rng.h"
#include "gate.h"
#include "fgate.h"
#include "Monster.h"
Map * initMap();
Map * initMapSaved(int size);
Map ** initListOfMaps();
Map ** genAllLevels(Monster** monsterTab);
Map ** genAllLevelsSaved(int* size, Monster** monsterTab);
#endif