#include "fmap.h"

Map * initMap() {
    Map * m = malloc(sizeof(Map));
    m->arr = genArr2d(100);
    return m;
}