#include "headers/heals.h"

int sizeTabHeals(Heals** tabHeals)
{
    int size = 0;
    for(int i = 0; tabHeals[i] != NULL; i++)
    {
        size = i;
    }
    return size;
}

Heals** initHeals()
{
    Heals** tabHeals;
    tabHeals = malloc(sizeof(Heals*)*15);
    char const* const fileName = "items/heals.txt";
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Fichier non ouvert");
    }
    char* line;
    line = malloc(sizeof(char)* 256);
    int index = 0;
    
    while(fgets(line, 256, file)) {
        tabHeals[index] = lineToStructHeals(line);
        index++;
    }
    fclose(file);
    return tabHeals;
}

Heals* lineToStructHeals(char* line)
{
    const char * separator = "|";
    int countElement = 0;
    char* token = strtok (line, separator);
    Heals* heal = malloc(sizeof(heal));
    while(token != NULL) {
        if(countElement == 0)
        {
            heal->objectId = atoi(token);
            countElement += 1;
        }
        else if(countElement == 1)
        {
            heal->name = malloc(sizeof(char) * 256);
            strcpy(heal->name, token);
            countElement += 1;
        }
        else
        {
            heal->heal = atoi(token);
            countElement = 0;
        }
        token = strtok (NULL, separator);
    }
    return heal;
}

void printHeals(Heals** tabHeals)
{
    int size_tab = sizeTabHeals(tabHeals);
    // printf("%d\n",size_tab);
    for (int i = 0; i <= size_tab; i++)
    {
        printf("Id : %d\n", tabHeals[i]->objectId);
        printf("Nom : %s\n", tabHeals[i]->name);
        printf("heal : %d\n\n", tabHeals[i]->heal);
    }     
}