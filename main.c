#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "map.h"
#include "player.h"

int main(int argc, char ** argv) {
    Map* wolrd; 
    wolrd = mapGridGenerator(1);
   // mapFreeGrid(wolrd);
    return 0;
}