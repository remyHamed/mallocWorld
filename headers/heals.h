#ifndef heals_h
#define heals_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct  Heals
{
    char* name;
    int heal;

    struct Heals* next;
};
typedef struct Heals Heals;

struct ListeHeals
{
    struct Heals* first;
};
typedef struct ListeHeals ListeHeals;

ListeHeals* initHeals();
void printListeHeals(ListeHeals* ListeHeals);

#endif