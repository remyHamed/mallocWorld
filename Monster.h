//
// Created by vette on 28/10/2021.
//
#ifndef MALLOCWORLD_MONSTER_H
#define MALLOCWORLD_MONSTER_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>

typedef struct Monster {
    int id;
    int zone;
    char* name;
    int hp;
    int damage;
    int exp;
}Monster;

Monster ** initMonster ();
Monster* lineToStructMonster(char*);
void printMonster(Monster**);

#endif //MALLOCWORLD_MONSTER_H
