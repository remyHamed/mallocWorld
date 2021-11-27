#ifndef weapons_h
#define weapons_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fFileReading.h"
typedef struct Weapons Weapons;
struct  Weapons {
    char* name;
    int damage;
    int durability;

    struct Weapons* next;
};

typedef struct ListeWeapons ListeWeapons;

Weapons** initWeapons();
Weapons* setOneWeapon(char** datasOfWeapons);
void printWeapons(Weapons** listeWeapons);
void freeWeapon(Weapons* arme);
#endif