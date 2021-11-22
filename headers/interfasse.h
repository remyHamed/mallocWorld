#ifndef interfasse_h
#define interfasse_h
#include <stdio.h>
#include "map.h"
#include "player.h"
void screenGame(Map** l, Player* gamer, int indexM);
void displayMoveMenu();
void move(Map* l, Player* p, int* continuing, int * index);
int meneGeneral();
int isMovable(Map* l,Player * p, int* index, int x, int y);
int gateMenu(Map* m, Player* p, int* index);
#endif