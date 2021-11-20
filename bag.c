#include "headers/bag.h"

char** createStartBag()
{
    char** bag;
    bag = malloc(sizeof(char*) * 4);
    for (int i = 0; i < 4; i++)
    {
        switch (i)
        {
            case 0:
                bag[i] = "Épée en bois|10"; // les outils et armes auront comme attributs la durabilité
                break;                      // les ressources et les potions auront comme attribut la quantité

            case 1:
                bag[i] = "Pioche en bois|10";
                break;

            case 2:
                bag[i] = "Serpe en bois|10";
                break;
            
            case 3:
                bag[i] = "Hache en bois|10";
                break;
        }
    }
    size_t n = sizeof(bag)/sizeof(bag[0]);
    printf("taille du tableau : %d\n", n);
    return bag;
}

void printBag(char** bag)
{
    for(int i = 0; i < 4; i++)
    {
        printf("%s\n", bag[i]);
    }
}