#include "headers/tools.h"
#include "headers/fFileReading.h"

Tools* findOneTool(Tools** tabTools, int index)
{
    int size_tab = countLines("items/tools.txt");
    for (int i = 0; i <= size_tab; i++)
    {
        if (tabTools[i]->objectId == index)
        {
            return tabTools[i];
        }
    }
}

char** structToTabTool(Tools* tool)
{
    char** tabItem = malloc(sizeof(char*) *4);
    char* elem = malloc(sizeof(char) * 255);
    for(int i = 0; i < 4; i++){
        tabItem[i] = malloc(sizeof(char)* 255);
    }
    for(int i = 0; i < 4; i++){
        switch (i){
            case 0:
                sprintf(elem, "%d", tool->objectId);
                strcpy(tabItem[i], elem);
                break;
            case 1:
                sprintf(elem, "%d", tool->size);
                strcpy(tabItem[i], elem);
                break;
            case 2:
                tabItem[i] = tool->name;
                break;
            case 3:
                sprintf(elem, "%d", tool->durability);
                strcpy(tabItem[i], elem);
                break;
        }
    }
    return tabItem;
}

Tools** initTools()
{
    char* line;
    char** dataFromLine;
    int index = 0;
    Tools** tabTools;
    int numOfToolsModel = countLines("items/tools.txt");
    tabTools = malloc(sizeof(Tools*) * numOfToolsModel);
    line = malloc(sizeof(char)* 256);
    FILE* file = fopen("items/tools.txt", "r");
    if (file == NULL) {
        printf("Fichier non ouvert");
    }
    while(fgets(line, 256, file)) {
        dataFromLine = lineSpliter(line);
        tabTools[index] = setOneTool(dataFromLine);
        for(int i = 0; i < 4; i++) {
            free(dataFromLine[i]);
        }
        index ++;
    }
    free(dataFromLine);
    fclose(file);
    free(line);
    return tabTools;
}

Tools* setOneTool(char** datasOfTools)
{
    Tools* tool = malloc(sizeof(Tools));
    tool->name = malloc(sizeof(char) * 256);
    tool->objectId = atoi(datasOfTools[0]);
    tool->size = atoi(datasOfTools[1]);
    strcpy(tool->name, datasOfTools[2]);
    tool->durability = atoi(datasOfTools[3]);
   

    return tool;
}

void printTools(Tools** tabTools) {
    
    for (int i = 0; i < 9; i++)
    {
        printf("ID : %d\n", tabTools[i]->objectId);
        printf("Size : %d\n", tabTools[i]->size);
        printf("Nom : %s\n", tabTools[i]->name);
        printf("Damage : %d\n\n", tabTools[i]->durability);
    }     
}

void freeTool(Tools * tool)
{
    free(tool->name);
    free(tool);
    printf(" tool free ok\n");
}