#include "headers/heals.h"
#include "headers/fFileReading.h"

Heals* findOneHeal(Heals** tabHeals, int index)
{
    int size_tab = countLines("items/heals.txt");
    for (int i = 0; i <= size_tab; i++)
    {
        if (tabHeals[i]->objectId == index)
        {
            return tabHeals[i];
        }
    }
}

char** structToTabHeal(Heals* heal)
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
                sprintf(elem, "%d", heal->objectId);
                strcpy(tabItem[i], elem);
                break;
            case 1:
                sprintf(elem, "%d", heal->size);
                strcpy(tabItem[i], elem);
                break;
            case 2:
                tabItem[i] = heal->name;
                break;
            case 3:
                sprintf(elem, "%d", heal->heal);
                strcpy(tabItem[i], elem);
                break;
        }
    }
    return tabItem;
}

Heals** initHeals()
{
    char* line;
    char** dataFromLine;
    int index = 0;
    Heals** tabHeals;
    int numOfHealsModel = countLines("items/heals.txt");
    tabHeals = malloc(sizeof(Heals*) * numOfHealsModel);
    line = malloc(sizeof(char)* 256);
    FILE* file = fopen("items/heals.txt", "r");
    if (file == NULL) {
        printf("Fichier non ouvert");
    }
    while(fgets(line, 256, file)) {
        dataFromLine = lineSpliter(line);
        tabHeals[index] = setOneHeal(dataFromLine);
        for(int i = 0; i < 4; i++) {
            free(dataFromLine[i]);
        }
        index ++;
    }
    free(dataFromLine);
    fclose(file);
    free(line);
    return tabHeals;
}

Heals* setOneHeal(char** datasOfHeals)
{
    Heals* heal = malloc(sizeof(Heals));
    heal->name = malloc(sizeof(char) * 256);
    heal->objectId = atoi(datasOfHeals[0]);
    heal->size = atoi(datasOfHeals[1]);
    strcpy(heal->name, datasOfHeals[2]);
    heal->heal = atoi(datasOfHeals[3]);
   

    return heal;
}

void printHeals(Heals** tabHeals) {
    
    for (int i = 0; i < 3; i++)
    {
        printf("ID : %d\n", tabHeals[i]->objectId);
        printf("Size : %d\n", tabHeals[i]->size);
        printf("Nom : %s\n", tabHeals[i]->name);
        printf("Damage : %d\n\n", tabHeals[i]->heal);
    }     
}

void freeHeal(Heals * heal)
{
    free(heal->name);
    free(heal);
    printf(" heal free ok\n");
}