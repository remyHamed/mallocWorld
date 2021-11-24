#ifndef interfasse_h
#define interfasse_h
#include <stdio.h>
#include "map.h"
#include "player.h"
void screenGame(Map** , Player* , int );
void displayMoveMenu();
void move(Map* , Player* , int* , int * , int *, int *);
int meneGeneral();
int isMovable(Map* ,Player * , int* , int , int );
int gateMenu(Map* , Player* , int* );
#endif