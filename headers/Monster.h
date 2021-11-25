//
// Created by vette on 28/10/2021.
//
#ifndef MALLOCWORLD_MONSTER_H
#define MALLOCWORLD_MONSTER_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>//ANCHOR, pourquoi avoir mis cette lib??

typedef struct Monster {
    int id;
    int zone;
    char* name;
    int hp;
    int damage;
    int exp;
}Monster;

Monster ** initMonster ();
Monster* lineToStructMonster(char* line);
void printMonster(Monster** tabMonster);
Monster * RandomMonster (Monster** tabMonster);
void freeMonster(Monster* bakemono);
#endif //MALLOCWORLD_MONSTER_H
