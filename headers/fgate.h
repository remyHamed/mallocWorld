#ifndef fgate_h
#define fgate_h
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "gate.h"
Gate* genGate(int xpos, int ypos, Map* nLevel, Map* laLevel, int levelYouMustHave);
#endif
