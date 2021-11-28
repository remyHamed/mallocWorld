#ifndef map_h
#define map_h
typedef struct  Map Map;
#include "gate.h"
#include "Monster.h"
struct Map 
{
    int levelLimit;
    int size;
    int ** arr;
    Gate * g;
    Monster** monstertab;
    int numOfMonster;
};
#endif