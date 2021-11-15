#include "headers/fmap.h"

Map * initMap() {
    Map * m = malloc(sizeof(Map));
    int s = genrandomSizeMap();
    m->arr = genArr2d(s); // ici integrer generation aléatoire de la taille de la carte
    m->size = s;
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
    first->levelLimit = 0;
    second->levelLimit = 3;
    third->levelLimit = 7;
    first->g = genGate(genrandomPosition(first->size), genrandomPosition(first->size),NULL, second,first->levelLimit);
    second->g = genGate(genrandomPosition(second->size), genrandomPosition(second->size),first, third,second->levelLimit);
    third->g = genGate(genrandomPosition(third->size), genrandomPosition(third->size),second, NULL,third->levelLimit); 
    list[0] = first;
    list[1] = second;
    list[2] = third;
    return list;
}