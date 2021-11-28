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
    player->arme = setOneWeaponByParams("epee en bois",1,10);
    player->def = setOneArmorByParams("Plastron en pierre",11, 4,10);
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

void checkAroundPlayer(Map* m, Player* p, int * index, int* gameContinue) {
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
    printf("valeur du tableau de la case à controler %d %d\n", poseTocheck[0],poseTocheck[1]);
    if(isWatchble(m,poseTocheck[0],poseTocheck[1])) {
        recognitionCaserecognition(m, p, index, poseTocheck, gameContinue);
    }
}

void recognitionCaserecognition(Map* m, Player* p, int* index, int* caseTocheck, int * gameContinue) {
    printf("\ndans recognitionCaserecognition \nvaleur du tableau de la case à controler %d %d\n", caseTocheck[0],caseTocheck[1]);
    if(m->arr[caseTocheck[0]][caseTocheck[1]] == -3) {
        gateMenu(m, p, index);
    }
    //TODO LOOP MONSTER
    for (size_t i = 0; i < m->numOfMonster; i++){
        if(m->monstertab[i]->x == caseTocheck[0] && m->monstertab[i]->y == caseTocheck[1]) {
            Battle(p, m->monstertab[i], p->arme,p->def, gameContinue, m);
        }
    }
    
    respawnMonster(m);
    //TODO LOOP ressource
}

int isWatchble(Map* m, int x, int y) {
    printf("in watchbl  x = %d y = %d\n", x, y);
    if(x < 0) {
        printf("1 faux\n");
        return 0;
    }
    if(x >= m->size) {
         printf("2 faux\n");
        return 0;
    }
    if(y < 0) {
         printf("3 faux\n");
        return 0;
    }
    if(y >= m->size) {
         printf("4 faux\n");
        return 0;
    }
    return 1;
}

void Leveling (Player * player) {
    if (player->exp >= 20 && player->level == 1) {
        player->level += 1;
        player->exp = 0;
        player->maxHp += 10;
        player->currentHp = player->maxHp;
        player->maxExp = 40;
    }
    if (player->exp >= 40 && player->level == 2) {
        player->level += 1;
        player->exp = 0;
        player->maxHp += 20;
        player->currentHp = player->maxHp;
        player->maxExp = 60;
    }
    if (player->exp >= 60 && player->level == 3) {
        player->level += 1;
        player->exp = 0;
        player->maxHp += 30;
        player->currentHp = player->maxHp;
        player->maxExp = 100;
    }
    if (player->exp >= 100 && player->level == 4) {
        player->level += 1;
        player->exp = 0;
        player->maxHp += 40;
        player->currentHp = player->maxHp;
        player->maxExp = 140;
    }
    if (player->exp >= 140 && (player->level >= 5 && player->level < 8)) {
        player->level += 1;
        player->exp = 0;
        player->maxHp += 50;
        player->currentHp = player->maxHp;
        player->maxExp = 280;
    }
    if (player->exp >= 280 && (player->level >= 8 && player->level < 10)) {
        player->level += 1;
        player->exp = 0;
        player->maxHp += 75;
        player->currentHp = player->maxHp;
    }
}