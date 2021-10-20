#ifndef object_h
#define object_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

struct  obj {
    char name[255];
    int x_position;
    int y_position;
    int isWeapon;
    int isNatural;
    int isCraftable
};                      
typedef struct obj obj;
#endif