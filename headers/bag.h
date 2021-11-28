#ifndef bag_h
#define bag_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bag Bag;
struct  Bag
{
    int size;
    char*** content;
};

Bag* initStartBag();
char*** createStartBag();
void printBag(char*** bag);
Bag* addItem(Bag* bag, char** item);
int isExist(Bag* bag, int index);
int* lookingAllRessources(Bag* bag);
int* lookingAllWeapons(Bag* bag);
int* lookingAllArmors(Bag* bag);
int* lookingAllHeals(Bag* bag);

#endif