#include "headers/weapons.h"

Weapons** initWeapons() {
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
        // printf("%s line\n", line);
        dataFromLine = lineSpliter(line);
        tabWeapons[index] = setOneWeapon(dataFromLine);
        for(int i = 0; i < 3; i++) {
            free(dataFromLine[i]);
        }
        index ++;
    }
    free(dataFromLine);
    fclose(file);
    free(line);
    return tabWeapons;
}

Weapons* setOneWeapon(char** datasOfWeapons) {
    Weapons* arme = malloc(sizeof(Weapons));
    arme->name = malloc(sizeof(char) * 256);
    strcpy(arme->name, datasOfWeapons[0]);
    arme->damage = atoi(datasOfWeapons[1]);
    arme->durability = atoi(datasOfWeapons[2]);
    return arme;
}

Weapons* setOneWeaponByParams(char* n, int dama, int dura) {
    Weapons* arme = malloc(sizeof(Weapons));
    arme->name = malloc(sizeof(char) * 256);
    strcpy(arme->name, n);
    arme->damage = dama;
    arme->durability = dura;
    return arme;
}

void printWeapons(Weapons** tabWeapons) {
    int size_tab = (sizeof(tabWeapons)/2) -1;
    // printf("%d\n",size_tab);
    for (int i = 0; i < 10; i++)
    {
        printf("Nom : %s\n", tabWeapons[i]->name);
        printf("Damage : %d\n", tabWeapons[i]->damage);
        printf("Durability : %d\n\n", tabWeapons[i]->durability);
    }     
}

void freeWeapon(Weapons * arme) {
    free(arme->name);
    free(arme);
    printf(" arme free ok\n");
}