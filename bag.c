#include "headers/bag.h"

char** lookingAllRessources(Bag* bag){
    char** ressourcesInBag = malloc(sizeof(char*) * 10);
    int count = 0;
    for(int i = 0; i < 10; i++){
        if(bag->content[i][0] == 1 || bag->content[i][0] == 8 || bag->content[i][0] == 9        // Oui c'est horrible
            || bag->content[i][0] == 10 || bag->content[i][0] == 19|| bag->content[i][0] == 20  // Oui j'ai honte
            || bag->content[i][0] == 30 || bag->content[i][0] == 31 || bag->content[i][0] == 32 // Non j'ai pas eu le temps de trouver mieux
            || bag->content[i][0] == 21)
        {
            ressourcesInBag[count] = malloc(sizeof(char)* 100);
            ressourcesInBag[count] == bag->content[i][2];
        }
    }
    return ressourcesInBag;
}

char** lookingAllWeapons(Bag* bag){
    char** weaponsInBag = malloc(sizeof(char*) * 10);
    int count = 0;
    for(int i = 0; i < 10; i++){
        if(bag->content[i][0] == 1 || bag->content[i][0] == 8 || bag->content[i][0] == 9        // Oui c'est horrible
            || bag->content[i][0] == 10 || bag->content[i][0] == 19|| bag->content[i][0] == 20  // Oui j'ai honte
            || bag->content[i][0] == 30 || bag->content[i][0] == 31 || bag->content[i][0] == 32 // Non j'ai pas eu le temps de trouver mieux
            || bag->content[i][0] == 21)
        {
            weaponsInBag[count] = malloc(sizeof(char)* 100);
            weaponsInBag[count] == bag->content[i][2];
        }
    }
    return weaponsInBag;
}

char** lookingAllArmors(Bag* bag){
    char** armorsInBag = malloc(sizeof(char*) * 10);
    int count = 0;
    for(int i = 0; i < 10; i++){
        if(bag->content[i][0] == 11 || bag->content[i][0] == 22 || bag->content[i][0] == 33)
        {
            armorsInBag[count] = malloc(sizeof(char)* 100);
            armorsInBag[count] == bag->content[i][2];
        }
    }
    return armorsInBag;
}

char** lookingAllHeals(Bag* bag){
    char** healsInBag = malloc(sizeof(char*) * 10);
    int count = 0;
    for(int i = 0; i < 10; i++){
        if(bag->content[i][0] == 15 || bag->content[i][0] == 26 || bag->content[i][0] == 34)
        {
            healsInBag[count] = malloc(sizeof(char)* 100);
            healsInBag[count] == bag->content[i][2];
        }
    }
    return healsInBag;
}

Bag* addItem(Bag* bag, char** item){
    int lastElem = bag->size;
    if (lastElem == 9){
        printf("Votre sac est plein il n'est pas possible d'y ajouter de nouveaux éléments !\n");
        return bag;
    }
    else{
        bag->content[lastElem] = item;
        bag->size = bag->size + 1;
        return bag;
    }
}

Bag* initStartBag(){
    Bag* bag = malloc(sizeof(Bag));
    bag->size = 4;
    bag->content = createStartBag();
    return bag;
}

char*** createStartBag(){
    char *** tabBag = malloc(sizeof(char**) * 10);
    for(int i = 0; i < 10; i++) {
        tabBag[i] = malloc(sizeof(char*) * 6);
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 6; j++) {
            tabBag[i][j] = calloc(255, sizeof(char));
        }
    }
    for (int i = 0; i < 4; i++){
        switch (i){
            case 0:
                tabBag[i][0] = "1"; // index
                tabBag[i][1] = "5"; // size
                tabBag[i][2] = "Epée en Bois";
                tabBag[i][3] = "1"; // dmg
                tabBag[i][4] = "10"; // dura
                tabBag[i][4] = "1"; // quantite
                break;

            case 1:
                tabBag[i][0] = "2";
                tabBag[i][1] = "4";
                tabBag[i][2] = "Pioche en Bois";
                tabBag[i][3] = "10";
                tabBag[i][4] = "1";
                break;

            case 2:
                tabBag[i][0] = "3";
                tabBag[i][1] = "4";
                tabBag[i][2] = "Serpe en Bois";
                tabBag[i][3] = "10";
                tabBag[i][4] = "1";
                break;
            
            case 3:
                tabBag[i][0] = "3";
                tabBag[i][1] = "4";
                tabBag[i][2] = "Hache en Bois";
                tabBag[i][3] = "10";
                tabBag[i][4] = "1";
                break;
        }
    }
    return tabBag;
}

void printBag(char*** bag) {
    for(int i = 0; i < 10; i++) {
        int size = atoi(bag[i][1]);
        for(int j = 0; j != size; j++) {
            printf("%s\n", bag[i][j]);
        }
    }
}