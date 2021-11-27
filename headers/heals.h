#ifndef heals_h
#define heals_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Heals Heals;
struct  Heals
{
    int objectId;
    int size;
    char* name;
    int heal;
};

Heals** initHeals();
int sizeTabHeals(Heals** tabHeals);
Heals* lineToStructHeals(char* line);
void printHeals(Heals** tabHeals);

#endif