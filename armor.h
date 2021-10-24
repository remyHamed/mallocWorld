#ifndef armor_h
#define armor_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Armor Armor;
struct Armor
{
    char* name;
    int resDamage;
    
    struct Armor* next;
};

typedef struct ListeArmor ListeArmor;
struct ListeArmor
{
    struct Armor* first;
};


ListeArmor* initArmor();
void printListeArmor (ListeArmor* ListeArmor);

#endif