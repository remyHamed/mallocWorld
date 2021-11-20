#ifndef ressources_h
#define ressources_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ressources Ressources;
struct  Ressources
{
    char* name;
    int holdLimit;
};

Ressources** initRessources();
void printRessources(Ressources**);
Ressources* lineToStructRessources(char*);

#endif