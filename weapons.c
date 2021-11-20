#include "headers/weapons.h"

Weapons** initWeapons()
{
    Weapons** tabWeapons;
    tabWeapons = malloc(sizeof(Weapons*)*10);
    char const* const fileName = "items/weapons.txt";
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Fichier non ouvert");
    }
    char* line;
    line = malloc(sizeof(char)* 256);
    int index = 0;
    
    while(fgets(line, 256, file)) {
        tabWeapons[index] = lineToStructWeapons(line);
        index++;
    }
    fclose(file);
    return tabWeapons;
}

Weapons* lineToStructWeapons(char* line)
{
    const char * separator = "|";
    int countElement = 0;
    char* token = strtok (line, separator);
    
    Weapons* weapon = malloc(sizeof(weapon));
    while(token != NULL) {
        
        if(countElement == 0)
        {
            weapon->name = malloc(sizeof(char) * 256);
            strcpy(weapon->name, token);
            countElement += 1;
        }
        else if (countElement == 1)
        {
            weapon->damage = atoi(token);
            countElement += 1;
        }
        else
        {
            weapon->durability = atoi(token);
            countElement = 0;
        }
        token = strtok (NULL, separator);
    }
    return weapon;
}

void printWeapons(Weapons** tabWeapons)
{
    // int size_tab = (sizeof(tabWeapons)/2) -1;
    // printf("%d\n",size_tab);
    for (int i = 0; i < 10; i++)
    {
        printf("Nom : %s\n", tabWeapons[i]->name);
        printf("Damage : %d\n", tabWeapons[i]->damage);
        printf("Durability : %d\n\n", tabWeapons[i]->durability);
    }     
}