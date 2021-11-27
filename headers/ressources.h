#ifndef ressources_h
#define ressources_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ressources Ressources;
struct  Ressources
{
    int objectId;
    int size;
    char* name;
    int holdLimit;
};

int sizeTabRessources(Ressources** tabRessources);
Ressources** initRessources();
void printRessources(Ressources** tabRessources);
Ressources* lineToStructRessources(char* line);

#endif