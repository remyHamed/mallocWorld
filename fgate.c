#include "headers/fgate.h"

Gate* genGate(int xpos, int ypos, int nLevel, int laLevel, int levelYouMustHave, Map*m) {
    Gate * g = malloc(sizeof(Gate));
    g->x  = xpos;
    g->y = xpos;
    g->nextLevel = nLevel;
    g->lastLevel = laLevel;
    g->levelLimit = levelYouMustHave;
    printf("xpos = %d  ypos = %d\n",xpos,ypos);
    m->arr[xpos][ypos] = -3;
    return g;
}
