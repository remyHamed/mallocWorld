#ifndef interfasse_h
#define interfasse_h
#include <stdio.h>
#include "map.h"
#include "player.h"
void screenGame(Map** l, Player* gamer, int indexM);
void displayMoveMenu();
void move(Map* l, Player* p, int* continuing);
int meneGeneral();
int isMovable(Map* l, int x, int y);
#endif