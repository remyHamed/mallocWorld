//
// Created by vette on 28/10/2021.
//
#ifndef MALLOCWORLD_MONSTER_H
#define MALLOCWORLD_MONSTER_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

typedef struct Monster {
    int index;
    char* name;
    int hp;
    int damage;
    int exp;
}Monster;

Monster * init ();
void choiceMonster (int, Monster*);

#endif //MALLOCWORLD_MONSTER_H
