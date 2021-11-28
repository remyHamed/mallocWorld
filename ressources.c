#include "headers/ressources.h"

Ressources* findOneRessource(Ressources** tabRessources, int index){
    int size_tab = countLines("items/ressources.txt");
    for (int i = 0; i < size_tab; i++){
        if (tabRessources[i]->objectId == index){
            return tabRessources[i];
        }
    }
}

char** structToTabRessource(Ressources* ressource){
    char** tabItem = malloc(sizeof(char*) *5);
    char* elem = malloc(sizeof(char) * 255);
    for(int i = 0; i < 5; i++){
        tabItem[i] = malloc(sizeof(char)* 255);
    }
    for(int i = 0; i < 5; i++){
        switch (i){
            case 0:
                sprintf(elem, "%d", ressource->objectId);
                strcpy(tabItem[i], elem);
                break;
            case 1:
                sprintf(elem, "%d", ressource->size);
                strcpy(tabItem[i], elem);
                break;
            case 2:
                tabItem[i] = ressource->name;
                break;
            case 3:
                sprintf(elem, "%d", ressource->holdLimit);
                strcpy(tabItem[i], elem);
                break;
            case 4:
                tabItem[i] = "1";
                break;
        }
    }
    free(elem);
    return tabItem;
}

Ressources** initRessources(){
    char* line;
    char** dataFromLine;
    int index = 0;
    Ressources** tabRessources;
    int numOfRessourcesModel = countLines("items/ressources.txt");
    tabRessources = malloc(sizeof(Ressources*) * numOfRessourcesModel);
    line = malloc(sizeof(char)* 256);
    FILE* file = fopen("items/ressources.txt", "r");
    if (file == NULL) {
        printf("Fichier non ouvert");
    }
    while(fgets(line, 256, file)) {
        dataFromLine = lineSpliter(line);
        tabRessources[index] = setOneRessource(dataFromLine);
        for(int i = 0; i < 4; i++) {
            free(dataFromLine[i]);
        }
        index ++;
    }
    free(dataFromLine);
    fclose(file);
    free(line);
    return tabRessources;
}

Ressources* setOneRessource(char** datasOfRessources){
    Ressources* ressource = malloc(sizeof(Ressources));
    ressource->name = malloc(sizeof(char) * 256);
    ressource->objectId = atoi(datasOfRessources[0]);
    ressource->size = atoi(datasOfRessources[1]);
    strcpy(ressource->name, datasOfRessources[2]);
    ressource->holdLimit = atoi(datasOfRessources[3]);
   
    return ressource;
}

void printRessources(Ressources** tabRessources) {
    for (int i = 0; i < 9; i++){
        printf("ID : %d\n", tabRessources[i]->objectId);
        printf("Size : %d\n", tabRessources[i]->size);
        printf("Nom : %s\n", tabRessources[i]->name);
        printf("Damage : %d\n\n", tabRessources[i]->holdLimit);
    }     
}

void printOneRessource(Ressources* ressource) {
    printf("ID : %d\n", ressource->objectId);
    printf("Size : %d\n", ressource->size);
    printf("Nom : %s\n", ressource->name);
    printf("Damage : %d\n", ressource->holdLimit);
}

void freeRessource(Ressources * ressource){
    free(ressource->name);
    free(ressource);
    printf(" ressource free ok\n");
}