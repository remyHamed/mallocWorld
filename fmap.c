#include "fmap.h"

Map * initMap() {
    Map * m = malloc(sizeof(Map));
    m->arr = genArr2d(100); // ici integrer generation aléatoire de la taille de la carte
    return m;
}