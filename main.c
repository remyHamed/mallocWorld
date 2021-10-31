#include <stdio.h>
#include <stdlib.h>
#include "fmap.h"
#include "arr2d.h"
#include "player.h"
#include "fplayer.h"
#include "interfasse.h"


int main(int argc, char ** argv) {
    Player * p1;
    Map** list;
    list = genAllLevels();
    p1 = genPlayer();
    screenGame( list, p1);
    free(p1);
    return 0;
}