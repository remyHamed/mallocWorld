#include "fmap.h"

Map * initMap() {
    Map * m = malloc(sizeof(Map));
    int s = genrandomSizeMap();
    m->arr = genArr2d(s); // ici integrer generation aléatoire de la taille de la carte
    m->size = s;
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
    first->levelLimit = 0;
    second->levelLimit = 3;
    third->levelLimit = 7;
    list[0] = first;
    list[1] = second;
    list[2] = third;
    return list;
}