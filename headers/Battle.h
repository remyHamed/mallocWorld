//
// Created by vette on 13/10/2021.
//

#ifndef battle_h
#define battle_h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Monster.h"
#include "player.h"
#include "fplayer.h"
#include "weapons.h"
#include "heals.h"
#include "armor.h"


void selectActions(Player * player, Monster * monster,Weapons * weapon, int *choice);
void Battle(Player *player, Monster* monster, Weapons * weapon, Armors * armor, int *gameContinue, Map *m);

#endif //MALLOCWORLD_BATTLE_H
