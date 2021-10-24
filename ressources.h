#ifndef ressourcesCraft_h
#define ressourcesCraft_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct  RessourcesCraft
{
    char* name;
    int holdLimit;

    struct RessourcesCraft* next;
};
typedef struct RessourcesCraft RessourcesCraft;


struct ListeRessourcesCraft
{
    struct RessourcesCraft* first;
};
typedef struct ListeRessourcesCraft ListeRessourcesCraft;

ListeRessourcesCraft* initRessourcesCraft();
void printListeRessourcesCraft(ListeRessourcesCraft* ListeRessourcesCraft);

#endif