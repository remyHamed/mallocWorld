#ifndef heals_h
#define heals_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fFileReading.h"

typedef struct Heals Heals;
struct  Heals
{
    int objectId;
    int size;
    char* name;
    int heal;
};

Heals** initHeals();
Heals* setOneHeal(char** datasOfHeals);
void printHeals(Heals** tabHeals);
void freeHeal(Heals * heal);
Heals* findOneHeal(Heals** tabHeals, int index);
char** structToTabHeal(Heals* heal);
void printOneHeal(Heals* heal);

#endif