#ifndef tools_h
#define tools_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tools Tools;
struct  Tools
{
    int objectId;
    int size;
    char* name;
    int durability;
};

int sizeTabTools(Tools** tabTools);
Tools** initTools();
Tools* lineToStructTools(char* line);
void printTools(Tools** tabTools);

#endif