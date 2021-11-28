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
Crafts* setOneCraft(char** datasOfCrafts);
void printCrafts(Crafts** tabCrafts);
void freeCraft(Crafts * craft);
#endif