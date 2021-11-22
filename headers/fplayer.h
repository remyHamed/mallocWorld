#ifndef fplayer_h
#define fplayer_h
#include <stdlib.h>
#include "player.h"
#include "fmap.h"
#include "map.h"
Player * initPlayer ();
void checkAroundPlayer(Map* m, Player* p, int * index);
void recognitionCaserecognition(Map* m, Player* p, int* index, int* caseTocheck);
#endif
