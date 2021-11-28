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
#include "headers/weapons.h"
#define NEW_GAME 1
#define LOAD_SAVED_GAME 2
#define END_GAME 3
int main(int argc, char **argv)
{
    Monster **tabmonster = initMonster();
    Weapons **tabweapon = initWeapons();
    Armors **tabarmor = initArmors();
    Map **list = NULL;
    Player *player = NULL;
    // Battle(player,tabmonster,tabweapon,tabarmor);
    int *input = malloc(sizeof(int));
    int *gameContinue = malloc(sizeof(int));
    int *size = malloc(sizeof(int) * 3);
    int *temp = malloc(sizeof(int));
    int live = 1;
    char *filename = "save.txt";
    int indexMap = 0;
    int selector = 0;
    *temp = 1;
    *input = 0;
    *gameContinue = 1;
    printf("1\n");
    do
    {
        fflush(stdin);
        fflush(stdout);
        selector = meneGeneral();
        if (selector == NEW_GAME)
        {
            list = genAllLevels(tabmonster);
            player = initPlayer();
            list[indexMap]->arr[0][0] = 1; // cette ligne place le joueur
            *gameContinue = 1;
        }
        if (selector == LOAD_SAVED_GAME && CheckFile(filename) == 1)
        {
            size = ResumeSize();
            list = genAllLevelsSaved(size, tabmonster);
            player = initPlayer();
            Resume(player, list);
            *gameContinue = 1;
            printf("chargement parti sauver\n");
        }

        if (selector == END_GAME)
        {
            *gameContinue = 0;
            live = 0;
        }
        while (*gameContinue)
        {
            if (*input != '\n')
            {
                screenGame(list, player, indexMap);
                checkAroundPlayer(list[indexMap], player, &indexMap, gameContinue); //TODO mettre le contunue en param
            }
            move(list[indexMap], player, gameContinue, &indexMap, input, temp);
        }
        Save(player, list);
        if (list != NULL)
        {
            SaveSize(list[0]->size, list[1]->size, list[2]->size);
        }
    } while (live);

    for (int i = 0; i < 22; i++)
    {
        freeMonster(tabmonster[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        freeWeapon(tabweapon[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        freeArmor(tabarmor[i]);
    }
    free(player);
    free(list); //TODO fonction de liberation de la liste
    free(size);
    return 0;
}