#ifndef fplayer_h
#define fplayer_h
#include <stdlib.h>
#include "player.h"
#include "fmap.h"
#include "map.h"
#include "interfasse.h"

Player * initPlayer ();
void checkAroundPlayer(Map* m, Player* p, int * index);
void recognitionCaserecognition(Map* m, Player* p, int* index, int* caseTocheck);
int isWatchble(Map* m, int x, int y);
#endif
