#ifndef fplayer_h
#define fplayer_h
#include <stdlib.h>
#include "player.h"
#include "fmap.h"
#include "map.h"
#include "interfasse.h"
#include "Battle.h"
#include "weapons.h"

Player * initPlayer ();
void checkAroundPlayer(Map* m, Player* p, int * index, int * gameContinue);
void recognitionCaserecognition(Map* m, Player* p, int* index, int* caseTocheck, int* gameContinue);
int isWatchble(Map* m, int x, int y);
void Leveling (Player * player);
#endif