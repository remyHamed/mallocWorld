#ifndef craft_h
#define craft_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Crafts Crafts;
struct  Crafts
{
    int objectId;
    char* name;
    int nbComposant1;
    char* composant1;
    int nbComposant2;
    char* composant2;
    int zone;
};

Crafts** initCrafts();
int sizeTabCrafts(Crafts** tabCrafts);
Crafts* lineToStructCrafts(char* line);
void printCrafts(Crafts** tabCrafts);

#endif