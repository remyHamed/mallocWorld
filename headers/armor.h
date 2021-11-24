#ifndef armor_h
#define armor_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Armors Armors;
struct Armors
{
    int objectId;
    char* name;
    int resDamage;
};

int sizeTabArmors(Armors** tabArmors);
Armors** initArmors();
void printArmors(Armors** tabArmors);
Armors* lineToStructArmors(char* line);

#endif