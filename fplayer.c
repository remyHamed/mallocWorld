#include "headers/fplayer.h"

Player * genPlayer() {
    Player * p;
    p = malloc(sizeof(Player));
    p->x = 0;
    p->y = 0;
    return p;
}

void diplayPlayerPosition(Map* level, Player* character) {
    for (int i = 0; i < level->size; i++) {
        for (int j = 0; j < level->size; j++) {
            if (i == character->x && j == character->y) {
                printf(" X");
            } else {
                printf(" %d",level->arr[i][j]);
            }
        }
        printf("\n");
    }
}