#include "headers/fgate.h"

Gate* genGate(int xpos, int ypos, Map* nLevel, Map* laLevel, int levelYouMustHave) {
    Gate * g = malloc(sizeof(Gate));
    g->x  = xpos;
    g->y = ypos;
    g->nextLevel = nLevel;
    g->lastLevel = laLevel;
    g->levelLimit = levelYouMustHave;
    return g;
}
