#include <stdio.h>
#include <stdlib.h>
#include "fmap.h"
#include "arr2d.h"


int main(int argc, char ** argv) {
    Map* first = initMap();
    first->levelLimit = 50;
    first->size = 100;
    printf("size = %d\n", first->size);
    printf("limit = %d\n", first->levelLimit);
    //setArr2d(first->arr, first->size);
    diplsayArr2d(first->arr,first->size); 
    free(first);    
    return 0;
}