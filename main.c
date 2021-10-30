#include <stdio.h>
#include <stdlib.h>
#include "fmap.h"
#include "arr2d.h"
#include "player.h"
#include "fplayer.h"


int main(int argc, char ** argv) {
    Player * p1;
    p1 = genPlayer();
    printf("%d\n", p1->x);
    printf("%d\n", p1->y);
    free(p1);
    return 0;
}