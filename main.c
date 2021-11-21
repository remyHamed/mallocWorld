#include <stdio.h>
#include <stdlib.h>
#include "headers/fmap.h"
#include "headers/arr2d.h"
#include "headers/player.h"
#include "headers/fplayer.h"
#include "headers/interfasse.h"
#include "headers/map.h"
#include "headers/gate.h"
#define NEW_GAME 1
#define LOAD_SAVED_GAME  2
#define END_GAME  3


int main(int argc, char ** argv) {
    Player * p1;
    Map** list;
    int indexMap = 0;
    int* gameContinue;
    int live = 1;
    gameContinue = malloc(sizeof(int));
    *gameContinue = 1;
    int selector = 0;
    do{
        fflush(stdin);
        fflush(stdout);
        selector = meneGeneral();
        if(selector == NEW_GAME) {
            list = genAllLevels();
            p1 = genPlayer();
            list[indexMap]->arr[0][0] = 1;
        }
        if(selector == LOAD_SAVED_GAME) {
            printf("chargement parti sauver");
            //ANCHOR SET LES ÉLÉMENTNT
            //LECTURE DES FICHIERS DE SAUVEGARDE ICI
            //RESSOURCE
            //CARTE
            //MONSTRE
            //ICI
        }
        if(selector == END_GAME) {
            *gameContinue = 0;
            live = 0;
        }
        while (*gameContinue)  {
            screenGame(list, p1, indexMap);
            checkAroundPlayer(list[indexMap], p1, &indexMap);
            //printf("\n x = %d\n", p1->x);
            //printf(" y = %d\n", p1->y);
            //printf("size map = %d\n", list[indexMap]->size);
            move(list[indexMap], p1, gameContinue);
        }
    } while(live);

    free(p1);
    return 0;
}