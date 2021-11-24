#include "headers/craft.h"

int sizeTabCrafts(Crafts** tabCraft)
{
    int size = 0;
    for(int i = 0; tabCraft[i] != NULL; i++)
    {
        size = i;
    }
    return size;
}

Crafts** initCrafts()
{
    Crafts** tabCraft;
    tabCraft = malloc(sizeof(Crafts*)*35);
    char const* const fileName = "items/craft.txt";
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Fichier non ouvert");
    }
    char* line;
    line = malloc(sizeof(char)* 256);
    int index = 0;
    
    while(fgets(line, 256, file)) {
        tabCraft[index] = lineToStructCrafts(line);
        index++;
    }
    fclose(file);
    return tabCraft;
}

Crafts* lineToStructCrafts(char* line)
{
    const char * separator = "|";
    int countElement = 0;
    char* token = strtok (line, separator);
    Crafts* craft = malloc(sizeof(Crafts));
    while(token != NULL) {
        switch (countElement)
        {
            case 0:
                craft->name = malloc(sizeof(char) * 256);
                strcpy(craft->name, token);
                countElement += 1;
                break;
        
            case 1:
                craft->nbComposant1 = atoi(token);
                countElement += 1;
                break;

            case 2:
                craft->composant1 = malloc(sizeof(char) * 256);
                strcpy(craft->composant1, token);
                countElement += 1;
                break;
            
            case 3:
                craft->nbComposant2 = atoi(token);
                countElement += 1;
                break;
            
            case 4:
                craft->composant2 = malloc(sizeof(char) * 256);
                strcpy(craft->composant2, token);
                countElement += 1;
                break;

            case 5:
                craft->zone = atoi(token);
                countElement = 0;
                break;
        }
        token = strtok (NULL, separator);
    }
    return craft;
}

void printCrafts(Crafts** tabCraft)
{
    int size_tab = sizeTabCrafts(tabCraft);
    for (int i = 0; i <= size_tab; i++)
    {
        printf("Nom : %s\n", tabCraft[i]->name);
        printf("NB1 : %d\n", tabCraft[i]->nbComposant1);
        printf("Composant 1 : %s\n", tabCraft[i]->composant1);
        printf("NB2 : %d\n", tabCraft[i]->nbComposant2);
        printf("Composant 2 : %s\n\n", tabCraft[i]->composant2);
        printf("Zone : %d\n", tabCraft[i]->zone);
    }     
}