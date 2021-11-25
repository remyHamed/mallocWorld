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
    Monster** tabmonster = initMonster();
    Weapons** tabweapon = initWeapons();
    Armors** tabarmor = initArmors();
    Map** list = NULL;
    Player* player = NULL;
    // Battle(player,tabmonster,tabweapon,tabarmor);
    int * input = malloc(sizeof(int));
    int * gameContinue = malloc(sizeof(int));
    int * size = malloc(sizeof(int)*3);
    int * temp  = malloc(sizeof(int));
    int live = 1;
    char * filename = "save.txt";
    int indexMap = 0;
    int selector = 0;
    *temp = 1 ;
    *input = 0 ;
    *gameContinue = 1;
      printf("1\n");   
    do{
        fflush(stdin);
        fflush(stdout);
        selector = meneGeneral();
        if(selector == NEW_GAME) {
            list = genAllLevels();
            player = initPlayer();
            list[indexMap]->arr[0][0] = 1;// cette ligne place le joueur
            *gameContinue = 1;
        }

        if(selector == LOAD_SAVED_GAME && CheckFile(filename) == 1) {
            size = ResumeSize();
            list = genAllLevelsSaved(size);
            player = initPlayer();
            Resume(player,list);
            *gameContinue = 1;
            // printf(" tab : %d\n",list[0]->arr[0][4]);
            // printf("%d\n",player->level);
            // printf("%d\n",player->exp);
            // printf("%d\n",player->maxExp);
            // printf("%d\n",player->currentHp);
            // printf("%d\n",player->maxHp);
            printf("chargement parti sauver\n");
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
            if (*input != '\n') {
                screenGame(list, player, indexMap);
                checkAroundPlayer(list[indexMap], player, &indexMap);
                //printf("\n x = %d\n", player->x);
                //printf(" y = %d\n", player->y);
                //printf("size map = %d\n", list[indexMap]->size);
            }
            move(list[indexMap], player, gameContinue, &indexMap, input, temp);
        }
        Save(player,list);
        if(list != NULL) {
            SaveSize(list[0]->size,list[1]->size,list[2]->size);
        }
    } while(live);
    printf("ok");
    for(int i = 0; i < 22; i++) {
        freeMonster(tabmonster[i]);
    }
     printf("hello\n");
    for(int i = 0; i < 10; i++) {
        freeWeapon(tabweapon[i]);
    }
    for(int i = 0; i < 3; i++) {
        freeArmors(tabarmor[i]);
    }
    free(player);
    free(list);//TODO fonction de liberation de la liste
    free(size);
    return 0;
}