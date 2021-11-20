#ifndef craft_h
#define craft_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Crafts Crafts;
struct  Crafts
{
    char* name;
    int nbComposant1;
    char* composant1;
    int nbComposant2;
    char* composant2;
};

Crafts** initCrafts();
Crafts* lineToStructCrafts(char*);
void printCrafts(Crafts**);

#endif