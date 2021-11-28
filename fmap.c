#include "headers/fmap.h"

Map * initMap() {
    Map * m = malloc(sizeof(Map));
    m->size = 50;//genrandomSizeMap();
    m->arr = genArr2d(m->size); 
    m->g = NULL;
    return m;
}

Map * initMapSaved(int size) {
    Map * m = malloc(sizeof(Map));
    m->size = size;
    m->arr = genArr2d(m->size); 
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
    arrRandPosition = genrandomPosition(first->size - 1);
    first->monstertab = genMonsterarrLevel( 0, 12, 18, monsterTab, first);
    putMonsterOnMap(first); 
    first->g = genGate(arrRandPosition[0], arrRandPosition[1], 0, 1,first->levelLimit, first);
    free(arrRandPosition);
    arrRandPosition = genrandomPosition(second->size - 1);
    second->monstertab = genMonsterarrLevel(1, 19, 25, monsterTab, second);
    putMonsterOnMap(second); 
    second->g = genGate(arrRandPosition[0], arrRandPosition[1],1, 2,second->levelLimit, second);
    free(arrRandPosition);
    arrRandPosition = genrandomPosition(third->size - 1);
    third->monstertab = genMonsterarrLevel( 2, 26, 32, monsterTab, third);
    putMonsterOnMap(third);
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

void respawnMonster(Map* m) {
    for (int i = 0; i < m->numOfMonster; i++) {
        if(m->monstertab[i]->isAlive == 0){
            m->monstertab[i]->status++;
            if (m->monstertab[i]->status == 15) {
                m->monstertab[i]->isAlive = 1;
            }
        }
    }
    for (int i = 0; i < m->numOfMonster; i++) {
         if(m->monstertab[i]->isAlive == 1 && m->arr[m->monstertab[i]->x][m->monstertab[i]->y] == 0) {
            m->arr[m->monstertab[i]->x][m->monstertab[i]->y] = m->monstertab[i]->id;
         }
    }
}
