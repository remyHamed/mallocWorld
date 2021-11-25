#include "headers/bag.h"

int sizeBag(char*** bag)
{
    int size = 0;
    for(int i = 0; bag[i] != NULL; i++)
    {
        size = i;
    }
    return size;
}

char*** createStartBag()
{
    char *** bag = malloc(sizeof(char**) * 10);
    for(int i = 0; i < 10; i++) {
        bag[i]= malloc(sizeof(char*));
    }
    for(int i = 0; i < 10; i++) {
      for(int j = 0; j < 10; j++) {
        bag[i][i] = malloc(sizeof(char) * 255);
      }
    }
    for (int i = 0; i < 4; i++)
    {
        switch (i){
            case 0:
                bag[i][0] = "Epée en Bois";
                bag[i][1] = "1";
                bag[i][2] = "10";
                break;

            case 1:
                bag[i][0] = "Pioche en Bois";
                bag[i][1] = "10";
                break;

            case 2:
                bag[i][0] = "Serpe en Bois";
                bag[i][1] = "10";
                break;
            
            case 3:
                bag[i][0] = "Hache en Bois";
                bag[i][1] = "10";
                break;
        }
    }
    return bag;
}

void printBag(char*** bag) {
    for(int i = 0; i < 10; i++) {
      for(int j = 0; j < 10; j++) {
       printf("%s\n", bag[i][j]);
      }
    }
}