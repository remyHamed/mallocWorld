#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "map.h"
#include "player.h"

int main(int argc, char ** argv) {
    map map;
    mapGridGenerator(&map);
    displayMap(&map);
    mapFreeGrid(&map);
    return 0;
}