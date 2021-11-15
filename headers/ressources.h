#ifndef ressources_h
#define ressources_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct  Ressources
{
    char* name;
    int holdLimit;
    int x;
    int y;

    struct Ressources* next;
};
typedef struct Ressources Ressources;


struct ListeRessources
{
    struct Ressources* first;
};
typedef struct ListeRessources ListeRessources;

ListeRessources* initRessources();
void printListeRessources(ListeRessources* ListeRessources);

#endif