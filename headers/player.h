//
// Created by vette on 29/10/2021.
//

#ifndef player_h 
#define player_h
#include <stdio.h>
typedef struct Player Player;
#include "weapons.h"
#include "armor.h"
struct Player {
    int currentHp;
    int maxHp;
    int exp;
    int maxExp;
    int level;
    int value;
    int x;
    int y;
    int orientation;// ANCHOR 
                    // 1 haut
                    // 2 gauche
                    // 3 droite
                    // 4 bas
    Weapons* arme;
    Armors* def;
};


#endif //MALLOCWORLD_PLAYER_H
