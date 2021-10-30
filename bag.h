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

    Bag* next;
};

typedef struct ListeBag ListeBag;
struct ListeBag
{
    Bag* first;
};

ListeBag* initBag();
void printBag(ListeBag* listeBag);

#endif