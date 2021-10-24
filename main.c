#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "map.h"
#include "player.h"

int main(int argc, char ** argv) {
    Map * world = genMapForTest();
    Player* p = creatPlayer();
    int moveCount = 0;
    do {
        movePlayer(p, world);
        displayMap(world, p);
        moveCount += 1;
    } while (moveCount < 6); 
    freeMap(world);
    free(p);
    return 0;
}