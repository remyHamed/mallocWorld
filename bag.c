#include "headers/bag.h"

// int sizeBag(char*** bag)
// {
//     int size = 0;
//     for(int i = 0; bag[i] != NULL; i++)
//     {
//         size = i;
//     }
//     return size;
// }

Bag* addItem(Bag* bag, char** item)
{
    int lastElem = bag->size;
    if (lastElem == 9)
    {
        printf("Votre sac est plein il n'est pas possible d'y ajouter de nouveaux éléments !\n");
        return bag;
    }
    else{
        bag->content[lastElem] = item;
        bag->size = bag->size + 1;
        return bag;
    }
}

Bag* initStartBag()
{
    Bag* bag = malloc(sizeof(Bag));
    bag->size = 4;
    bag->content = createStartBag();
    return bag;
}

char*** createStartBag()
{
    char *** tabBag = malloc(sizeof(char**) * 10);
    for(int i = 0; i < 10; i++) 
    {
        tabBag[i] = malloc(sizeof(char*) * 5);
    }

    for(int i = 0; i < 10; i++) 
    {
        for(int j = 0; j < 5; j++) 
        {
            tabBag[i][j] = calloc(255, sizeof(char));
        }
    }
    for (int i = 0; i < 4; i++)
    {
        switch (i){
            case 0:
                tabBag[i][0] = "1";
                tabBag[i][1] = "5";
                tabBag[i][2] = "Epée en Bois";
                tabBag[i][3] = "1";
                tabBag[i][4] = "10";
                break;

            case 1:
                tabBag[i][0] = "2";
                tabBag[i][1] = "4";
                tabBag[i][2] = "Pioche en Bois";
                tabBag[i][3] = "10";
                break;

            case 2:
                tabBag[i][0] = "3";
                tabBag[i][1] = "4";
                tabBag[i][2] = "Serpe en Bois";
                tabBag[i][3] = "10";
                break;
            
            case 3:
                tabBag[i][0] = "3";
                tabBag[i][1] = "4";
                tabBag[i][2] = "Hache en Bois";
                tabBag[i][3] = "10";
                break;
        }
    }
    return tabBag;
}

void printBag(char*** bag) 
{
    for(int i = 0; i < 10; i++) 
    {
        int size = atoi(bag[i][1]);

        for(int j = 0; j != size; j++) 
        {
            printf("%s\n", bag[i][j]);
        }
    }
}