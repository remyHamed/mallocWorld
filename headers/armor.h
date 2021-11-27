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

int sizeTabArmors(Armors** tabArmors);
Armors** initArmors();
void printArmors(Armors** tabArmors);
Armors* lineToStructArmors(char* line);
char** structToTabStrArmor(Armors* armor);
Armors* findOneArmor(Armors** tabArmors, int index);

#endif