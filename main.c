#include <stdio.h>
#include <stdlib.h>
#include "headers/Battle.h"
#include "headers/Save.h"
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
int main() {
    Monster ** tabmonster = initMonster();
    Weapons ** tabweapon = initWeapons();
    Armors ** tabarmor = initArmors();
    Map** list;
    Player * player;
    // Battle(player,tabmonster,tabweapon,tabarmor);
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
            player = initPlayer();
            list[indexMap]->arr[0][0] = 1;
        }
        if(selector == LOAD_SAVED_GAME) {
            Resume(player,list);
            *gameContinue = 1;
            // printf(" tab : %d\n",list[0]->arr[0][4]);
            // printf("%d\n",player->level);
            // printf("%d\n",player->exp);
            // printf("%d\n",player->maxExp);
            // printf("%d\n",player->currentHp);
            // printf("%d\n",player->maxHp);
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
            screenGame(list, player, indexMap);
            checkAroundPlayer(list[indexMap], player, &indexMap);
            //printf("\n x = %d\n", player->x);
            //printf(" y = %d\n", player->y);
            //printf("size map = %d\n", list[indexMap]->size);
            move(list[indexMap], player, gameContinue, &indexMap);
        }
        Save(player,list);
    } while(live);

    free (tabweapon);
    free (tabmonster);
    free (tabarmor);
    free (player);
    return 0;
}