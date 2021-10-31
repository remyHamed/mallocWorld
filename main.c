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
    int indexMap = 0;
    int* gameContinue;
    gameContinue = malloc(sizeof(int));
    *gameContinue = 1;
    list = genAllLevels();
    p1 = genPlayer();
    while (*gameContinue)  {
        screenGame(list, p1, indexMap);
        move(list[indexMap], p1, gameContinue);
    }
    free(p1);
    return 0;
}