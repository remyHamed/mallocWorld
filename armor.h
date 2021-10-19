#ifndef armor_h
#define armor_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Armor
{
    char* name;
    int resDamage;

    Armor* next;
};
typedef struct Armor Armor;

struct ListeArmor
{
    ListeArmor* first;
};
typedef struct ListeArmor ListeArmor;

ListeArmor* initArmor();
void printListeArmor (ListeArmor* ListeArmor);

#endif armor_h