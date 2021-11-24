#include "headers/armor.h"

int sizeTabArmors(Armors** tabArmor)
{
    int size = 0;
    for(int i = 0; tabArmor[i] != NULL; i++)
    {
        size = i;
    }
    return size;
}

Armors** initArmors()
{
    Armors** tabArmor;
    tabArmor = malloc(sizeof(Armors*)*10);
    char const* const fileName = "items/armor.txt";
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Fichier non ouvert");
    }
    char* line;
    line = malloc(sizeof(char)* 256);
    int index = 0;
    
    while(fgets(line, 256, file)) {
        tabArmor[index] = lineToStructArmors(line);
        index++;
    }
    fclose(file);
    return tabArmor;
}

Armors* lineToStructArmors(char* line)
{
    const char * separator = "|";
    int countElement = 0;
    char* token = strtok (line, separator);
    Armors* armor = malloc(sizeof(Armors));
    while(token != NULL) {
        if(countElement == 0)
        {
            armor->objectId = atoi(token);
            countElement += 1;
        }
        else if (countElement == 1)
        {
            armor->name = malloc(sizeof(char) * 256);
            strcpy(armor->name, token);
            countElement += 1;
        }
        else
        {
            armor->resDamage = atoi(token);
            countElement = 0;
        }
        token = strtok (NULL, separator);
    }
    return armor;
}

void printArmors(Armors** tabArmor)
{
    int size_tab = sizeTabArmors(tabArmor);
    for (int i = 0; i <= size_tab; i++)
    {
        printf("Id : %d\n", tabArmor[i]->objectId);
        printf("Nom : %s\n", tabArmor[i]->name);
        printf("ResDamage : %d\n\n", tabArmor[i]->resDamage);
    }     
}