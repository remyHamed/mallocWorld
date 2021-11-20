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
};

Weapons** initWeapons();
void printWeapons(Weapons** listeWeapons);
Weapons* lineToStructWeapons(char*);

#endif