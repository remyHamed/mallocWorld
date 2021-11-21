//
// Created by vette on 30/10/2021.
//

#include "headers/Leveling.h"

void Leveling (Player * player) {
    if (player->exp >= 20 && player->level == 1) {
        player->level += 1;
        player->exp = 0;
        player->maxHp += 10;
        player->currentHp = player->maxHp;
        player->maxExp = 40;
    }
    if (player->exp >= 40 && player->level == 2) {
        player->level += 1;
        player->exp = 0;
        player->maxHp += 20;
        player->currentHp = player->maxHp;
        player->maxExp = 60;
    }
    if (player->exp >= 60 && player->level == 3) {
        player->level += 1;
        player->exp = 0;
        player->maxHp += 30;
        player->currentHp = player->maxHp;
        player->maxExp = 100;
    }
    if (player->exp >= 100 && player->level == 4) {
        player->level += 1;
        player->exp = 0;
        player->maxHp += 40;
        player->currentHp = player->maxHp;
        player->maxExp = 140;
    }
    if (player->exp >= 140 && (player->level >= 5 && player->level < 8)) {
        player->level += 1;
        player->exp = 0;
        player->maxHp += 50;
        player->currentHp = player->maxHp;
        player->maxExp = 280;
    }
    if (player->exp >= 280 && (player->level >= 8 && player->level < 10)) {
        player->level += 1;
        player->exp = 0;
        player->maxHp += 75;
        player->currentHp = player->maxHp;
    }
}