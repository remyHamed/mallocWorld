#ifndef armor_h
#define armor_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Armors Armors;
struct Armors
{
    int objectId;
    int size;
    char* name;
    int resDamage;
};

Armors** initArmors();
Armors* setOneArmor(char** datasOfArmors);
void printArmors(Armors** tabArmors);
void freeArmor(Armors * arme);
Armors* findOneArmor(Armors** tabArmors, int index);
char** structToTabArmor(Armors* armor);

#endif