#ifndef tools_h
#define tools_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tools Tools;
struct  Tools
{
    char* name;
    int durability;

    Tools* next;
};

typedef struct ListeTools ListeTools;
struct ListeTools
{
    Tools* first;
};

ListeTools* initTools();
void printListeTools(ListeTools* ListeTools);

#endif