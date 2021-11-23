#include "headers/fmap.h"

Map * initMap() {
    Map * m = malloc(sizeof(Map));
    m->size = 50;//genrandomSizeMap();
    m->arr = genArr2d(m->size); 
    printf("\n initMap  m->size = %d\n", m->size);
    m->g = NULL;
    return m;
}
/*
Map * initMapSaved(int size) {
    Map * m = malloc(sizeof(Map));
    m->size = size;
    m->arr = genArr2d(m->size); 
    printf("\n initMap  m->size = %d\n", m->size);
    m->g = NULL;
    return m;
}
*/
Map ** initListOfMaps() {
    Map** list = malloc(sizeof(Map*) * 3);
    return list;
}
/*
Map ** genAllLevelsSaved() {
    int size;//ANCHOR Récupeer la taille des cartes
    Map** list = initListOfMaps();
    Map* first = initMapSaved();
    Map* second = initMapSaved();
    Map* third = initMapSaved();
    first->levelLimit = 3;
    second->levelLimit = 3;
    third->levelLimit = 7;
}
*/

Map ** genAllLevels() {
    Map** list = initListOfMaps(); 
    Map* first = initMap();
    Map* second = initMap();
    Map* third = initMap();
    int * arrRandPosition;
    first->levelLimit = 3;
    second->levelLimit = 3;
    third->levelLimit = 7;
    arrRandPosition = genrandomPosition(first->size);
    first->g = genGate(arrRandPosition[0], arrRandPosition[1], 0, 1,first->levelLimit, first);
    free(arrRandPosition);
    arrRandPosition = genrandomPosition(second->size);
    second->g = genGate(arrRandPosition[0], arrRandPosition[1],1, 2,second->levelLimit, second);
    free(arrRandPosition);
    arrRandPosition = genrandomPosition(third->size);
    third->g = genGate(arrRandPosition[0], arrRandPosition[1],1, 2,third->levelLimit, third); 
    list[0] = first;
    list[1] = second;
    list[2] = third;
    return list;
}


void putGateOnMap(Map** list) {
    //list[0]->arr[list[0]->g->x][list[0]->g->y] = -3;
    //list[1]->arr[list[1]->g->x][list[1]->g->y] = -3;
    //list[2]->arr[list[2]->g->x][list[2]->g->y] = -3;
    list[0]->arr[1][1] = -3;
    list[1]->arr[1][1] = -3;
    list[2]->arr[1][1] = -3;
}