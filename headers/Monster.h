//
// Created by vette on 28/10/2021.
//
#ifndef MALLOCWORLD_MONSTER_H
#define MALLOCWORLD_MONSTER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct Monster Monster;
#include "fFileReading.h"
#include "Map.h"
#include "rng.h"

struct Monster {
    int id;
    int zone;
    char* name;
    int hp;
    int damage;
    int exp;
    int x;
    int y;
    int status;// count each round before respown
    int isAlive;
};

Monster ** initMonster ();
Monster* setMonster(char** dataOfMonster);
void printMonster(Monster** tabMonster);
Monster * RandomMonster (Monster** tabMonster);
Monster **genMonsterarrLevel(int indexMap, int numIdMonsterMin, int numIdMonsterMax, Monster **model, Map *m);
void putMonsterOnMap(Map *m);
void freeMonster(Monster* bakemono);
#endif //MALLOCWORLD_MONSTER_H
