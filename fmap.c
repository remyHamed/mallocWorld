#include "headers/fmap.h"

Map * initMap() {
    printf("debut function init map\n");
    Map * m = malloc(sizeof(Map));
    printf("1\n");
    m->size = 50;//genrandomSizeMap();
    printf("2\n");
    m->arr = genArr2d(m->size); 
    printf("3\n");
    printf("\n initMap  m->size = %d\n", m->size);
    m->g = NULL;
    printf("FIN init map\n");
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
    printf("1\n");
    int * arrRandPosition;
    first->levelLimit = 3;
    second->levelLimit = 3;
    third->levelLimit = 7;
    printf("2\n");
    arrRandPosition = genrandomPosition(first->size);
    first->monstertab = genMonsterarrLevel( 0, 12, 18, monsterTab, first);
    first->g = genGate(arrRandPosition[0], arrRandPosition[1], 0, 1,first->levelLimit, first);
    printf("4\n");
    free(arrRandPosition);
    printf("5\n");
    arrRandPosition = genrandomPosition(second->size);
    printf("1++++++++++1\n");
    second->monstertab = genMonsterarrLevel(1, 19, 25, monsterTab, second);
    second->g = genGate(arrRandPosition[0], arrRandPosition[1],1, 2,second->levelLimit, second);
    printf("7\n");
    free(arrRandPosition);
    printf("8\n");
    arrRandPosition = genrandomPosition(third->size);
    third->monstertab = genMonsterarrLevel( 2, 26, 32, monsterTab, third);
    third->g = genGate(arrRandPosition[0], arrRandPosition[1],1, 2,third->levelLimit, third); 
    list[0] = first;
    list[1] = second;
    list[2] = third;
    printf("FIN init map\n");
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
