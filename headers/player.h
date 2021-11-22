//
// Created by vette on 29/10/2021.
//

#ifndef MALLOCWORLD_PLAYER_H
#define MALLOCWORLD_PLAYER_H
#include <stdio.h>
#include <malloc.h>

typedef struct Player {
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
}Player;

Player * initPlayer ();

#endif //MALLOCWORLD_PLAYER_H
