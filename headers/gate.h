#ifndef gate_h
#define gate_h
#include <stdio.h>
#include <stdlib.h>
typedef struct Gate Gate;
#include "map.h"
struct Gate {
    int x;
    int y;
    int nextLevel;
    int lastLevel;
    int levelLimit;
};
#endif