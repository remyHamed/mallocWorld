#include "headers/armor.h"

Armors* findOneArmor(Armors** tabArmors, int index){
    int size_tab = countLines("items/armors.txt");
    for (int i = 0; i < size_tab; i++){
        if (tabArmors[i]->objectId == index){
            return tabArmors[i];
        }
    }
}

char** structToTabArmor(Armors* armor){
    char** tabItem = malloc(sizeof(char*) *5);
    char* elem = malloc(sizeof(char) * 255);
    for(int i = 0; i < 5; i++){
        tabItem[i] = malloc(sizeof(char)* 255);
    }
    for(int i = 0; i < 5; i++){
        switch (i){
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
            case 4:
                tabItem[i] = "1";
                break;
        }
    }
    return tabItem;
}

Armors** initArmors(){
    char* line;
    char** dataFromLine;
    int index = 0;
    Armors** tabArmors;
    int numOfArmorsModel = countLines("items/armors.txt");
    tabArmors = malloc(sizeof(Armors*) * numOfArmorsModel);
    line = malloc(sizeof(char)* 256);
    FILE* file = fopen("items/armors.txt", "r");
    if (file == NULL) {
        printf("Fichier non ouvert");
    }
    while(fgets(line, 256, file)) {
        dataFromLine = lineSpliter(line);
        tabArmors[index] = setOneArmor(dataFromLine);
        for(int i = 0; i < 4; i++) {
            free(dataFromLine[i]);
        }
        index ++;
    }
    free(dataFromLine);
    fclose(file);
    free(line);
    return tabArmors;
}

Armors* setOneArmor(char** datasOfArmors){
    Armors* armure = malloc(sizeof(Armors));
    armure->name = malloc(sizeof(char) * 256);
    armure->objectId = atoi(datasOfArmors[0]);
    armure->size = atoi(datasOfArmors[1]);
    strcpy(armure->name, datasOfArmors[2]);
    armure->resDamage = atoi(datasOfArmors[3]);

    return armure;
}

void printArmors(Armors** tabArmors) {
    for (int i = 0; i < 3; i++){
        printf("ID : %d\n", tabArmors[i]->objectId);
        printf("Size : %d\n", tabArmors[i]->size);
        printf("Nom : %s\n", tabArmors[i]->name);
        printf("Damage : %d\n\n", tabArmors[i]->resDamage);
    }     
}

void freeArmor(Armors * armure){
    free(armure->name);
    free(armure);
    printf(" armure free ok\n");
}