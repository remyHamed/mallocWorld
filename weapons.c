#include "headers/weapons.h"

Weapons** initWeapons() {
    int index = 0;
    Weapons** tabWeapons;
    char* line;
    tabWeapons = malloc(sizeof(Weapons*)*10);
    FILE* file = fopen("items/weapons.txt", "r");
    if (file == NULL) {
        printf("Fichier non ouvert");
    }
    line = malloc(sizeof(char)* 256);
    while(fgets(line, 256, file)) {
        // printf("%s line\n", line);
        tabWeapons[index] = lineToStructWeapons(line);
        index++;
    }
    fclose(file);
    free(line);
    return tabWeapons;
}

Weapons* lineToStructWeapons(char* line) {
    const char * separator = "|";
    int countElement = 0;
    char* token = strtok (line, separator);
    //char * temp = malloc(sizeof(char)*256);
    //strcpy(temp, token);
    Weapons* arme = malloc(sizeof(arme));
    while(token != NULL) {
        if(countElement == 0) {
            // printf("%s token1\n", token);
            arme->name = malloc(sizeof(char) * 256);
            strcpy(arme->name, token);
            countElement += 1;
        
        } 
        else if (countElement == 1) {
            // printf("%s token2\n", token);
            //weapon->weapon = malloc(sizeof(int));
            arme->damage = atoi(token);
            countElement += 1;
        } 
        else {
            // printf("%s token3\n", token);
            arme->durability = atoi(token);
            countElement = 0;
        }
        token = strtok (NULL, separator);
    }
    printf("Nom : %s\n", arme->name);
    printf("Damage : %d\n", arme->damage);
    printf("Durability : %d\n\n", arme->durability);
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