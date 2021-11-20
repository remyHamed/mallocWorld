#include "headers/tools.h"

Tools** initTools()
{
    Tools** tabTools;
    tabTools = malloc(sizeof(Tools*)*10);
    char const* const fileName = "items/tools.txt";
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Fichier non ouvert");
    }
    char* line;
    line = malloc(sizeof(char)* 256);
    int index = 0;
    
    while(fgets(line, 256, file)) {
        tabTools[index] = lineToStructTools(line);
        index++;
    }
    fclose(file);
    return tabTools;
}

Tools* lineToStructTools(char* line)
{
    const char * separator = "|";
    int countElement = 0;
    char* token = strtok (line, separator);
    Tools* tool = malloc(sizeof(tool));
    while(token != NULL) {
        if(countElement == 0)
        {
            tool->name = malloc(sizeof(char) * 256);
            strcpy(tool->name, token);
            countElement += 1;
        }
        else
        {
            tool->durability = atoi(token);
            countElement = 0;
        }
        token = strtok (NULL, separator);
    }
    return tool;
}

void printTools(Tools** tabTools)
{
    // int size_tab = (sizeof(tabTools)/2) -1;
    // printf("%d\n",size_tab);
    for (int i = 0; i < 6; i++)
    {
        printf("Nom : %s\n", tabTools[i]->name);
        printf("Durability : %d\n\n", tabTools[i]->durability);
    }     
}