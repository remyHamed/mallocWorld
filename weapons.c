#include "headers/weapons.h"

Weapons* findOneWeapon(Weapons** tabWeapons, int index)
{
    int size_tab = countLines("items/weapons.txt");
    for (int i = 0; i < size_tab; i++){
        if (tabWeapons[i]->objectId == index){
            return tabWeapons[i];
        }
    }
}

char** structToTabWeapon(Weapons* weapon){
    char** tabItem = malloc(sizeof(char*) *6);
    char* elem = malloc(sizeof(char) * 255);
    for(int i = 0; i < 6; i++){
        tabItem[i] = malloc(sizeof(char)* 255);
    }
    for(int i = 0; i < 6; i++){
        switch (i){
            case 0:
                sprintf(elem, "%d", weapon->objectId);
                strcpy(tabItem[i], elem);
                break;
            case 1:
                sprintf(elem, "%d", weapon->size);
                strcpy(tabItem[i], elem);
                break;
            case 2:
                tabItem[i] = weapon->name;
                break;
            case 3:
                sprintf(elem, "%d", weapon->damage);
                strcpy(tabItem[i], elem);
                break;
            case 4:
                sprintf(elem, "%d", weapon->durability);
                strcpy(tabItem[i], elem);
                break;
            case 5:
                tabItem[i] = "1";
                break;
        }
    }
    free(elem);
    return tabItem;
}

Weapons** initWeapons(){
    char* line;
    char** dataFromLine;
    int index = 0;
    Weapons** tabWeapons;
    int numOfWeaponsModel = countLines("items/weapons.txt");
    tabWeapons = malloc(sizeof(Weapons*) * numOfWeaponsModel);
    line = malloc(sizeof(char)* 256);
    FILE* file = fopen("items/weapons.txt", "r");
    if (file == NULL) {
        printf("Fichier non ouvert");
    }
    while(fgets(line, 256, file)) {
        dataFromLine = lineSpliter(line);
        tabWeapons[index] = setOneWeapon(dataFromLine);
        for(int i = 0; i < 5; i++) {
            free(dataFromLine[i]);
        }
        index ++;
    }
    free(dataFromLine);
    fclose(file);
    free(line);
    return tabWeapons;
}

Weapons* setOneWeapon(char** datasOfWeapons){
    Weapons* arme = malloc(sizeof(Weapons));
    arme->name = malloc(sizeof(char) * 256);
    arme->objectId = atoi(datasOfWeapons[0]);
    arme->size = atoi(datasOfWeapons[1]);
    strcpy(arme->name, datasOfWeapons[2]);
    arme->damage = atoi(datasOfWeapons[3]);
    arme->durability = atoi(datasOfWeapons[4]);

    return arme;
}

void printWeapons(Weapons** tabWeapons) {
    int size_tab = (sizeof(tabWeapons)/2) -1;
    // printf("%d\n",size_tab);
    for (int i = 0; i < 10; i++){
        printf("ID : %d\n", tabWeapons[i]->objectId);
        printf("Size : %d\n", tabWeapons[i]->size);
        printf("Nom : %s\n", tabWeapons[i]->name);
        printf("Damage : %d\n", tabWeapons[i]->damage);
        printf("Durability : %d\n\n", tabWeapons[i]->durability);
    }     
}

void printOneWeapon(Weapons* weapon) {
    printf("ID : %d\n", weapon->objectId);
    printf("Size : %d\n", weapon->size);
    printf("Nom : %s\n", weapon->name);
    printf("Damage : %d\n", weapon->damage);
    printf("Durability : %d\n\n", weapon->durability);
}

void freeWeapon(Weapons * arme)
{
    free(arme->name);
    free(arme);
    printf(" arme free ok\n");
}