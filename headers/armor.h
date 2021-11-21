#ifndef armor_h
#define armor_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Armors Armors;
struct Armors
{
    char* name;
    int resDamage;
};

Armors** initArmors();
void printArmors(Armors**);
Armors* lineToStructArmors(char*);

#endif