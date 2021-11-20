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
};

Tools** initTools();
Tools* lineToStructTools(char*);
void printTools(Tools** ListeTools);

#endif