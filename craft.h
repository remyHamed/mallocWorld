#ifndef craft_h
#define craft_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct  Craft
{
    char* name;
    char* composant1;
    int nbComposant1;
    char* composant2;
    int nbComposant2;

    Craft* next;
};
typedef struct Craft Craft;

struct ListeCraft
{
    Craft *first;
};
typedef struct ListeCraft ListeCraft;


ListeCraft* initCraft();
void printListeCraft(ListeCraft* listeCraft);

#endif craft_h