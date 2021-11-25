#include "headers/armor.h"

Armors** initArmors() {
    Armors** tabArmor;
    int index = 0;
    char* line;
    tabArmor = malloc(sizeof(Armors*)*3);
    line = malloc(sizeof(char)* 256);
    FILE* file = fopen("items/armor.txt", "r");
    if (file == NULL) {
        printf("Fichier non ouvert");
    }
    while(fgets(line, 256, file)) {
        tabArmor[index] = lineToStructArmors(line);
         printf("Nom : %s\n", tabArmor[index]->name);
        printf("ResDamage : %d\n\n", tabArmor[index]->resDamage);
        index++;
    }
    fclose(file);
    free(line);
    return tabArmor;
}

Armors* lineToStructArmors(char* line) {
    const char * separator = "|";
    int countElement = 0;
    char* token = strtok (line, separator);
    Armors* armor = malloc(sizeof(Armors));
    while(token != NULL) {
        if(countElement == 0) {
            armor->name = malloc(sizeof(char) * 256);
            strcpy(armor->name, token);
            countElement += 1;
        }
        else {
            armor->resDamage = atoi(token);
            countElement = 0;
        }
        token = strtok (NULL, separator);
    }
    return armor;
}

void printArmors(Armors** tabArmor) {
    // int size_tab = (sizeof(tabArmor)/2) -1;
    // printf("%d\n",size_tab);
    for (int i = 0; i < 3; i++) {
        printf("Nom : %s\n", tabArmor[i]->name);
        printf("ResDamage : %d\n\n", tabArmor[i]->resDamage);
    }     
}

void freeArmors(Armors* armure) {
    free(armure->name);
    free(armure);
    printf(" armure free ok\n");
}