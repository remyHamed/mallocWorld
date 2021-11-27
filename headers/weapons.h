#ifndef weapons_h
#define weapons_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Weapons Weapons;
struct  Weapons
{
    int objectId;
    int size;
    char* name;
    int damage;
    int durability;
};

int sizeTabWeapons(Weapons** tabWeapons);
Weapons** initWeapons();
void printWeapons(Weapons** tabWeapons);
Weapons* lineToStructWeapons(char* line);


#endif