#include "fmap.h"

Map * initMap() {
    Map * m = malloc(sizeof(Map));
    int s = genrandomSizeMap();
    m->arr = genArr2d(s); // ici integrer generation aléatoire de la taille de la carte
    m->size = s;
    return m;
}
