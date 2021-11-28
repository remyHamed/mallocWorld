#ifndef ressources_h
#define ressources_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fFileReading.h"

typedef struct Ressources Ressources;
struct  Ressources
{
    int objectId;
    int size;
    char* name;
    int holdLimit;
};

Ressources** initRessources();
Ressources* setOneRessource(char** datasOfRessources);
void printRessources(Ressources** tabRessources);
void freeRessource(Ressources * ressource);
Ressources* findOneRessource(Ressources** tabRessources, int index);
char** structToTabRessource(Ressources* ressource);
void printOneRessource(Ressources* ressource);

#endif