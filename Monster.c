//
// Created by vette on 28/10/2021.
//
#include "Monster.h"

Monster * init () {
    srand(time(NULL));
    Monster * monster = malloc(sizeof(Monster));
    monster->index = rand() % 98;
    if (monster->index < 12) {
        while (monster->index < 12) {
            monster->index = rand() % 98;
        }
    }
    if (monster->index >= 12) {
        choiceMonster(monster->index, monster);
    }
    return monster;
}

void choiceMonster (int index, Monster* monster) {
    if (index >=12 && index < 40) {
        monster->name = "Wolf";
        monster->hp = 100;
        monster->damage = 10;
        monster->exp = 5;
    }
    if (index >=41 && index < 70) {
        monster->name = "tiger";
        monster->hp = 120;
        monster->damage = 15;
        monster->exp = 10;
    }
    if (index >=71 && index < 98) {
        monster->name = "Bear";
        monster->hp = 140;
        monster->damage = 20;
        monster->exp = 15;
    }
}