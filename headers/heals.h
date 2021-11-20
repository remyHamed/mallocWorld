#ifndef heals_h
#define heals_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Heals Heals;
struct  Heals
{
    char* name;
    int heal;
};

Heals** initHeals();
Heals* lineToStructHeals(char*);
void printHeals(Heals**);

#endif