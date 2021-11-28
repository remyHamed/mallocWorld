#ifndef weapons_h
#define weapons_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fFileReading.h"

typedef struct Weapons Weapons;
struct  Weapons
{
    int objectId;
    int size;
    char* name;
    int damage;
    int durability;
};

Weapons** initWeapons();
Weapons* setOneWeapon(char** datasOfWeapons);
void printWeapons(Weapons** tabWeapons);
void freeWeapon(Weapons * arme);
Weapons* findOneWeapon(Weapons** tabWeapons, int index);
char** structToTabWeapon(Weapons* weapon);

#endif