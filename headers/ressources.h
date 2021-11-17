#ifndef ressources_h
#define ressources_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct  Ressources
{
    char* name;
    int holdLimit;

    struct Ressources* next;
};
typedef struct Ressources Ressources;

Ressources** initRessources();
void printRessources(Ressources**);
Ressources* lineToStructRessources(char*);

#endif