//
// Created by vette on 30/10/2021.
//

#include "Leveling.h"

void Leveling (Player * player) {
    if (player->exp >= 25 && player->level == 1) {
        player->level += 1;
        player->exp = 0;
        player->maxHp += 10;
        player->currentHp = player->maxHp;
    }
    if (player->exp >= 30 && player->level == 2) {
        player->level += 1;
        player->exp = 0;
        player->maxHp += 20;
        player->currentHp = player->maxHp;
    }
    if (player->exp >= 35 && player->level == 3) {
        player->level += 1;
        player->exp = 0;
        player->maxHp += 30;
        player->currentHp = player->maxHp;
    }
    if (player->exp >= 40 && player->level == 4) {
        player->level += 1;
        player->exp = 0;
        player->maxHp += 40;
        player->currentHp = player->maxHp;
    }
    if (player->exp >= 45 && (player->level == 5 || (player->level >= 6 && player->level < 8))) {
        player->level += 1;
        player->exp = 0;
        player->maxHp += 50;
        player->currentHp = player->maxHp;
    }
    if (player->exp >= 50 && (player->level == 8 || (player->level >= 9 && player->level < 10))) {
        player->level += 1;
        player->exp = 0;
        player->maxHp += 75;
        player->currentHp = player->maxHp;
    }
}