#ifndef fplayer_h
#define fplayer_h
#include <stdlib.h>
#include "player.h"
#include "fmap.h"
#include "map.h"
Player * genPlayer();
void checkAroundPlayer(Map* m, Player* p);
#endif
