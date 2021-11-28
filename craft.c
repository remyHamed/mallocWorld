#include "headers/craft.h"

Crafts** initCrafts()
{
    char* line;
    char** dataFromLine;
    int index = 0;
    Crafts** tabCrafts;
    int numOfCraftsModel = countLines("items/crafts.txt");
    tabCrafts = malloc(sizeof(Crafts*) * numOfCraftsModel);
    line = malloc(sizeof(char)* 256);
    FILE* file = fopen("items/crafts.txt", "r");
    if (file == NULL) {
        printf("Fichier non ouvert");
    }
    while(fgets(line, 256, file)) {
        dataFromLine = lineSpliter(line);
        tabCrafts[index] = setOneCraft(dataFromLine);
        for(int i = 0; i < 6; i++) {
            free(dataFromLine[i]);
        }
        index ++;
    }
    free(dataFromLine);
    fclose(file);
    free(line);
    return tabCrafts;
}

Crafts* setOneCraft(char** datasOfCrafts)
{
    Crafts* craft = malloc(sizeof(Crafts));
    craft->name = malloc(sizeof(char) * 256);
    craft->composant1 = malloc(sizeof(char) * 256);
    craft->composant2 = malloc(sizeof(char) * 256);
    strcpy(craft->name, datasOfCrafts[0]);
    craft->nbComposant1 = atoi(datasOfCrafts[1]);
    strcpy(craft->composant1, datasOfCrafts[2]);
    craft->nbComposant2 = atoi(datasOfCrafts[3]);
    strcpy(craft->composant2, datasOfCrafts[4]);
    craft->zone = atoi(datasOfCrafts[5]);
   

    return craft;
}

void printCrafts(Crafts** tabCrafts) {
    
    for (int i = 0; i < 25 ; i++)
    {
       
        printf("Nom : %s\n", tabCrafts[i]->name);
        printf("Nb1 : %d\n", tabCrafts[i]->nbComposant1);
        printf("Composant 1 : %s\n", tabCrafts[i]->composant1);
        printf("Nb2 : %d\n", tabCrafts[i]->nbComposant2);
        printf("Composant 2 : %s\n", tabCrafts[i]->composant2);
        printf("Zone : %d\n\n", tabCrafts[i]->zone);
      
    }     
}

void freeCraft(Crafts * craft)
{
    free(craft->name);
    free(craft->composant1);
    free(craft->composant2);
    free(craft);
    printf(" craft free ok\n");
}