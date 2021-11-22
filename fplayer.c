#include "headers/fplayer.h"

Player * initPlayer () {
    Player * player = malloc(sizeof(Player));
    player->currentHp = 100;
    player->maxHp = 100;
    player->exp = 0;
    player->maxExp = 20;
    player->level = 1;
    player->x = 0;
    player->y = 0;
    player->orientation = 3;
    player->value = 1;
    return player;
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

void checkAroundPlayer(Map* m, Player* p, int * index) {
    int poseTocheck[2] = {0};
    switch (p->orientation) {
        case 1:
            printf("\tl'orientation est en haut\n");
            poseTocheck[0] = p->x - 1;
            poseTocheck[1] = p->y;
            break;
        case 2:
            printf("\tl'orientation est a gauche\n");
            poseTocheck[0] = p->x;
            poseTocheck[1] = p->y - 1;
            break;
        case 3:
            printf("\tl'orientation est a droite\n");
            poseTocheck[0] = p->x;
            poseTocheck[1] = p->y + 1;
            break;
        case 4:
            printf("\tl'orientation est en bas\n");
            poseTocheck[0] = p->x + 1;
            poseTocheck[1] = p->y;
            break;
    }
    recognitionCaserecognition(m, p, index, &poseTocheck);
}

void recognitionCaserecognition(Map* m, Player* p, int* index, int* caseTocheck){
    if(m->arr[caseTocheck[0]][caseTocheck[1]] == -3) {
        printf("changement map");
    }
}