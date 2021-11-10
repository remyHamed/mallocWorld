#ifndef gate_h
#define gate_h
#include "player.h"
#include "map.h"
struct Gate {
    enum linking {oneAnd2, twoAnd3};
    int x;
    int y;
};
typedef struct Gate Gate;
#endif