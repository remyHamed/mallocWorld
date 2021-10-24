#ifndef craft_h
#define craft_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Craft Craft;
struct  Craft
{
    char* name;
    char* composant1;
    int nbComposant1;
    char* composant2;
    int nbComposant2;

    Craft* next;
};

typedef struct ListeCraft ListeCraft;
struct ListeCraft
{
    Craft *first;
};

ListeCraft* initCraft();
void printListeCraft(ListeCraft* listeCraft);

#endif