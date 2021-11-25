#include "headers/fmap.h"

Map * initMap() {
    Map * m = malloc(sizeof(Map));
    m->size = 50;//genrandomSizeMap();
    m->arr = genArr2d(m->size); 
    printf("\n initMap  m->size = %d\n", m->size);
    m->g = NULL;
    return m;
}

Map * initMapSaved(int size) {
    Map * m = malloc(sizeof(Map));
    m->size = size;
    m->arr = genArr2d(m->size); 
    printf("\n initMap  m->size = %d\n", m->size);
    m->g = NULL;
    return m;
}

Map ** initListOfMaps() {
    Map** list = malloc(sizeof(Map*) * 3);
    return list;
}

Map ** genAllLevelsSaved(int* size) {
    Map** list = initListOfMaps();
    Map* first = initMapSaved(size[0]);
    Map* second = initMapSaved(size[1]);
    Map* third = initMapSaved(size[2]);
    first->levelLimit = 3;
    second->levelLimit = 3;
    third->levelLimit = 7;
    list[0] = first;
    list[1] = second;
    list[2] = third;
    return list;
}

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

int isOutofBound(Map* m, int* arr) {
    if(arr[0] < 0) {
        return 1;
    }
    if(arr[0] >= m->size) {
         return 1;
    }
    if(arr[1] < 0) {
        return 1;
    }
    if(arr[1] < m->size) {
        return 1;
    }
    return 0;
}
