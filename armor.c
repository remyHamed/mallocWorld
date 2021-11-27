#include "headers/armor.h"

int sizeTabArmors(Armors** tabArmor)
{
    int size = 0;
    for(int i = 0; tabArmor[i] != NULL; i++)
    {
        size = i;
    }
    printf("taille armures: %d", size);
    return size;
}

Armors* findOneArmor(Armors** tabArmors, int index)
{
    int size_tab = sizeTabArmors(tabArmors);
    for (int i = 0; i <= size_tab; i++)
    {
        if (tabArmors[i]->objectId == index)
        {
            return tabArmors[i];
        }
    }
}

char** structToTabStrArmor(Armors* armor)
{
    char** tabItem = malloc(sizeof(char*) *4);
    char* elem = malloc(sizeof(char) * 255);
    for(int i = 0; i < 4; i++)
    {
        tabItem[i] = malloc(sizeof(char)* 255);
    }
    for(int i = 0; i < 4; i++)
    {
        switch (i)
        {
            case 0:
                sprintf(elem, "%d", armor->objectId);
                strcpy(tabItem[i], elem);
                break;
            case 1:
                sprintf(elem, "%d", armor->size);
                strcpy(tabItem[i], elem);
                break;
            case 2:
                tabItem[i] = armor->name;
                break;
            case 3:
                sprintf(elem, "%d", armor->resDamage);
                strcpy(tabItem[i], elem);
                break;
        }
    }
    return tabItem;
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
        else if(countElement == 1)
        {
            armor->size = atoi(token);
            countElement += 1;
        }
        else if (countElement == 2)
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
        printf("Size : %d\n", tabArmor[i]->size);
        printf("Nom : %s\n", tabArmor[i]->name);
        printf("ResDamage : %d\n\n", tabArmor[i]->resDamage);
    }     
}