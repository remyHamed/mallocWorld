#include <stdio.h>
#include <stdlib.h>
#include "headers/fmap.h"
#include "headers/arr2d.h"
#include "headers/player.h"
#include "headers/fplayer.h"
#include "headers/interfasse.h"
#include "headers/map.h"
#include "headers/gate.h"


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
        checkAroundPlayer(list[indexMap], p1);
        printf("\n x = %d\n", p1->x);
        printf(" y = %d\n", p1->y);
        printf("size map = %d\n", list[indexMap]->size);
        move(list[indexMap], p1, gameContinue);
    }
    free(p1);
    return 0;
}