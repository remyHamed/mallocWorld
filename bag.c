#include "headers/bag.h"

int isExist(Bag* bag, int index){
    int sizeBag = bag->size;
    for(int i = 0; i < sizeBag; i++){
        int actualID = atoi(bag->content[i][0]);
        if(index == actualID){
            return 1;
        }
    }
    return 0;
}

int* lookingAllRessources(Bag* bag){
    int* ressourcesInBag = malloc(sizeof(int) * 10);
    int count = 0;
    int sizeBag = bag->size;
    for(int i = 0; i < sizeBag; i++){
        if(bag->content[i][0] == "5" || bag->content[i][0] == "6" || bag->content[i][0] == "7"        // Oui c'est horrible
            || bag->content[i][0] == "16" || bag->content[i][0] == "17" || bag->content[i][0] == "18"  // Oui j'ai honte
            || bag->content[i][0] == "27" || bag->content[i][0] == "28" || bag->content[i][0] == "29") // Non j'ai pas eu le temps de trouver mieux
        {
            ressourcesInBag[count] == atoi(bag->content[i][0]);
            count += 1;
        }
    }
    return ressourcesInBag;
}

int* lookingAllWeapons(Bag* bag){
    int* weaponsInBag = malloc(sizeof(int) * 10);
    int count = 0;
    int sizeBag = bag->size;
    for(int i = 0; i < sizeBag; i++){
        if(bag->content[i][0] == "1" || bag->content[i][0] == "8" || bag->content[i][0] == "9"       // Oui c'est horrible
            || bag->content[i][0] == "10" || bag->content[i][0] == "19" || bag->content[i][0] == "20"  // Oui j'ai honte
            || bag->content[i][0] == "30" || bag->content[i][0] == "31" || bag->content[i][0] == "32" // Non j'ai pas eu le temps de trouver mieux
            || bag->content[i][0] == "21")
        {
            weaponsInBag[count] == atoi(bag->content[i][0]);
            count += 1;
        }
    }
    return weaponsInBag;
}

int* lookingAllArmors(Bag* bag){
    int* armorsInBag = malloc(sizeof(int) * 10);
    int count = 0;
    int sizeBag = bag->size;
    for(int i = 0; i < sizeBag; i++){
        if(bag->content[i][0] == "11" || bag->content[i][0] == "22" || bag->content[i][0] == "33")
        {
            armorsInBag[count] == atoi(bag->content[i][0]);
            count += 1;
        }
    }
    return armorsInBag;
}

int* lookingAllHeals(Bag* bag){
    int* healsInBag = malloc(sizeof(int) * 10);
    int count = 0;
    int sizeBag = bag->size;
    for(int i = 0; i < sizeBag; i++){
        if(bag->content[i][0] == "15" || bag->content[i][0] == "26" || bag->content[i][0] == "34")
        {
            healsInBag[count] == atoi(bag->content[i][0]);
            count += 1;
        }
    }
    return healsInBag;
}

Bag* addItem(Bag* bag, char** item){
    int lastElem = bag->size;
    int sizeItem = atoi(item[2]);
    int index = atoi(item[0]);
    if (lastElem == 9){
        printf("Votre sac est plein il n'est pas possible d'y ajouter de nouveaux éléments !\n");
        return bag;
    }
    else{
        if (isExist(bag, index) == 1){
            item[sizeItem + 1] = item[sizeItem + 1] + 1;
            bag->content[lastElem] = item;
            bag->size = bag->size + 1;
            return bag;
        }else{
            bag->content[lastElem] = item;
            bag->size = bag->size + 1;
            return bag;
        }
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
            tabBag[i][j] = malloc(sizeof(char) * 255);
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

void printBag(Bag* bag) {
    int sizeBag = bag->size;
    for(int i = 0; i < sizeBag; i++) {
        int size = atoi(bag->content[i][1]);
        for(int j = 0; j < size + 1; j++) {
            printf("%s\n", bag->content[i][j]);
        }
        printf("\n");
    }
}