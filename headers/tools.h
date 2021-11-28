#ifndef tools_h
#define tools_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fFileReading.h"

typedef struct Tools Tools;
struct  Tools
{
    int objectId;
    int size;
    char* name;
    int durability;
};

void freeTool(Tools * armure);
void printTools(Tools** tabTools);
void printOneTool(Tools* tool);
Tools* setOneTool(char** datasOfTools);
Tools** initTools();

#endif