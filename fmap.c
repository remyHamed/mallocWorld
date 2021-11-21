#include "headers/fmap.h"

Map * initMap() {
    Map * m = malloc(sizeof(Map));
    m->size = 50;//genrandomSizeMap();
    m->arr = genArr2d(m->size); 
    printf("\n initMap  m->size = %d\n", m->size);
    m->g = NULL;
    return m;
}

Map ** initListOfMaps() {
    Map** list = malloc(sizeof(Map*) * 3);
    return list;
}

Map ** genAllLevels() {
    Map** list = initListOfMaps(); 
    Map* first = initMap();
    Map* second = initMap();
    Map* third = initMap();
    int * arrRandPosition;
    first->levelLimit = 0;
    second->levelLimit = 3;
    third->levelLimit = 7;
    arrRandPosition = genrandomPosition(first->size);
    first->g = genGate(arrRandPosition[0], arrRandPosition[1], 0, 1,first->levelLimit);
    free(arrRandPosition);
    arrRandPosition = genrandomPosition(second->size);
    second->g = genGate(arrRandPosition[0], arrRandPosition[1],1, 2,second->levelLimit);
    free(arrRandPosition);
    arrRandPosition = genrandomPosition(third->size);
    third->g = genGate(arrRandPosition[0], arrRandPosition[1],1, 2,third->levelLimit); 
    list[0] = first;
    list[1] = second;
    list[2] = third;
    return list;
}    