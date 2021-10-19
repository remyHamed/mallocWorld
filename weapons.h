#ifndef weapons_h
#define weapons_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Weapons Weapons;
struct  Weapons
{
    char* name;
    int damage;
    int durability;

    Weapons* next;
};

typedef struct ListeWeapons ListeWeapons;
struct ListeWeapons
{
    Weapons* first;
};

#endif weapons_h