#ifndef ressourcesCraft_h
#define ressourcesCraft_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct  RessourcesCraft
{
    char* name;
    int holdLimit;

    RessourcesCraft* next;
};
typedef struct RessourcesCraft RessourcesCraft;


struct ListeRessourcesCraft
{
    RessourcesCraft* first;
};
typedef struct ListeRessourcesCraft ListeRessourcesCraft;

#endif ressourcesCraft_h