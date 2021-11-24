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

Map ** genAllLevelsSaved(int* size, Monster** monsterTab) {
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

Map ** genAllLevels(Monster** monsterTab) {
    Map** list = initListOfMaps(); 
    Map* first = initMap();
    Map* second = initMap();
    Map* third = initMap();
    int * arrRandPosition;
    first->levelLimit = 3;
    second->levelLimit = 3;
    third->levelLimit = 7;
    arrRandPosition = genrandomPosition(first->size);
    first->monstertab = genMonsterarrLevel( 0, 12, 18, monsterTab, first);
    first->g = genGate(arrRandPosition[0], arrRandPosition[1], 0, 1,first->levelLimit, first);
    free(arrRandPosition);
    arrRandPosition = genrandomPosition(second->size);
    printf("1++++++++++1\n");
    second->monstertab = genMonsterarrLevel(1, 19, 25, monsterTab, second);
    second->g = genGate(arrRandPosition[0], arrRandPosition[1],1, 2,second->levelLimit, second);
    free(arrRandPosition);
    arrRandPosition = genrandomPosition(third->size);
    third->monstertab = genMonsterarrLevel( 2, 26, 32, monsterTab, third);
    third->g = genGate(arrRandPosition[0], arrRandPosition[1],1, 2,third->levelLimit, third); 
    list[0] = first;
    list[1] = second;
    list[2] = third;
    return list;
}
