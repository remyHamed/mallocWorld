#include "headers/ressources.h"

int sizeTabRessources(Ressources** tabRessources)
{
    int size = 0;
    for(int i = 0; tabRessources[i] != NULL; i++)
    {
        size = i;
    }
    return size;
}

Ressources** initRessources()
{
    Ressources** tabRessources;
    tabRessources = malloc(sizeof(Ressources*)*12);
    char const* const fileName = "items/ressources.txt";
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Fichier non ouvert");
    }
    char* line;
    line = malloc(sizeof(char)* 256);
    int index = 0;
    
    while(fgets(line, 256, file)) {
        tabRessources[index] = lineToStructRessources(line);
        index++;
    }
    fclose(file);
    return tabRessources;
}

Ressources* lineToStructRessources(char* line)
{
    const char * separator = "|";
    int countElement = 0;
    char* token = strtok (line, separator);
    Ressources* ressource = malloc(sizeof(ressource));
    while(token != NULL) {
        if(countElement == 0)
        {
            ressource->objectId = atoi(token);
            countElement += 1;
        }
        else if(countElement == 1)
        {
            ressource->name = malloc(sizeof(char) * 256);
            strcpy(ressource->name, token);
            countElement += 1;
        }
        else
        {
            ressource->holdLimit = atoi(token);
            countElement = 0;
        }
        token = strtok (NULL, separator);
    }
    return ressource;
}

void printRessources(Ressources** tabRessources)
{
    int size_tab = sizeTabRessources(tabRessources);
    for (int i = 0; i <= size_tab; i++)
    {
        printf("Id : %d\n", tabRessources[i]->objectId);
        printf("Nom : %s\n", tabRessources[i]->name);
        printf("Hold limit : %d\n\n", tabRessources[i]->holdLimit);
    }     
}