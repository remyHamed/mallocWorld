#include <stdio.h>
#include <stdlib.h>
#include "fmap.h"
#include "arr2d.h"


int main(int argc, char ** argv) {
    Map* first = initMap();
    first->levelLimit = 50;
    first->size = 2;
    printf("sie =%d", first->size);
    printf("\n limit = %d", first->levelLimit);
    setArr2d(first->arr, first->size);

    free(first);    
    return 0;
}