//
// Created by vette on 13/10/2021.
//

#ifndef MALLOCWORLD_BATTLE_H
#define MALLOCWORLD_BATTLE_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Monster.h"
#include "Player.h"
#include "weapons.h"
#include "heals.h"
#include "armor.h"
#include "Leveling.h"

void choices (int*, int*, int*, int*, int*);
void Battle(Player *, Monster **);

#endif //MALLOCWORLD_BATTLE_H
