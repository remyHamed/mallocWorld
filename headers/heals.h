#ifndef heals_h
#define heals_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct  Heals
{
    char* name;
    int heal;

    struct Heals* next;
};
typedef struct Heals Heals;

Heals** initHeals();
Heals* lineToStructHeals(char*);
void printHeals(Heals**);

#endif