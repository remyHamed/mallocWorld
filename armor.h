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
    
    Armor* next;
};

typedef struct ListeArmor ListeArmor;
struct ListeArmor
{
    ListeArmor* first;
};


ListeArmor* initArmor();
void printListeArmor (ListeArmor* ListeArmor);

#endif armor_h