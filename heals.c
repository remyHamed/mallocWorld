#include "headers/heals.h"

Heals** initHeals()
{
    Heals** tabHeals;
    tabHeals = malloc(sizeof(Heals*)*10);
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
    // int size_tab = (sizeof(tabHeals)/2) -1;
    // printf("%d\n",size_tab);
    for (int i = 0; i < 3; i++)
    {
        printf("Nom : %s\n", tabHeals[i]->name);
        printf("heal : %d\n\n", tabHeals[i]->heal);
    }     
}