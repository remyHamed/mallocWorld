#include "map.h"



Map * initMap(){
    Map * nwWolrd;
    nwWolrd = malloc(sizeof(Map));
    nwWolrd->gird = malloc(sizeof(int));
    nwWolrd->levelLImit->malloc(sizeof(int));
    return nwWolrd;
    }

void freeMap(Map * nwWolrd) {
    free(nwWolrd->size);
    free(nwWolrd->levelLImit);
    free(nwWolrd);
}