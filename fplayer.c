#include "headers/fplayer.h"

Player * genPlayer() {
    Player * p;
    p = malloc(sizeof(Player));
    p->x = 0;
    p->y = 0;
    p->orientation = 3;
    p->value = 1;
    p->level = 4;
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

void checkAroundPlayer(Map* m, Player* p, int * index) {
    int poseTochekc[2] = {0};
    switch (p->orientation) {
        case 1:
            printf("\tl'orientation est en haut\n");
            poseTochekc[0] = p->x - 1;
            poseTochekc[1] = p->y;
            break;
        case 2:
            printf("\tl'orientation est a gauche\n");
            poseTochekc[0] = p->x;
            poseTochekc[1] = p->y - 1;
            break;
        case 3:
            printf("\tl'orientation est a droite\n");
            poseTochekc[0] = p->x;
            poseTochekc[1] = p->y + 1;
            break;
        case 4:
            printf("\tl'orientation est en bas\n");
            poseTochekc[0] = p->x + 1;
            poseTochekc[1] = p->y;
            break;
    }
    printf("valeur du tableau de la case à controler %d %d\n", poseTochekc[0],poseTochekc[1]);
    recognitionCaserecognition(m, p, index, poseTochekc);
}

void recognitionCaserecognition(Map* m, Player* p, int* index, int* caseTocheck){
    printf("\ndans recognitionCaserecognition \nvaleur du tableau de la case à controler %d %d\n", caseTocheck[0],caseTocheck[1]);
    if(m->arr[caseTocheck[0]][caseTocheck[1]] == -3) {
        gateMenu(m, p, index);
    }
    //TODO LOOP MONSTER
    //TODO LOOP ressource
}