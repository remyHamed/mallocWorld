//
// Created by vette on 29/10/2021.
//

#include "Player.h"

Player * initPlayer (){
    Player * player = malloc(sizeof(Player));
    player->currentHp = 100;
    player->maxHp = 100;
    player->exp = 0;
    player->level = 1;
    return player;
}