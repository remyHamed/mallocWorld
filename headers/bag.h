#ifndef bag_h
#define bag_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bag Bag;
struct  Bag
{
    char* name;
    int quantity;
};

ListeBag** initBag();
void printBag(ListeBag**);

#endif