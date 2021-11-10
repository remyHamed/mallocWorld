#include "headers/interfasse.h"

void screenGame(Map** l, Player* gamer, int indexM) {

    for (int i = gamer->x - 20 ; i < gamer->x + 20; i+= 1) {
        if(i < 0 || i > l[indexM]->size) {
            printf("\n");
            continue;
        }
        for (int j = gamer->y - 20; j < gamer->y + 20; j+= 1) {
            if(i == gamer->x && j == gamer->y) {
                printf(" X");
                continue;
            }
            if(j < 0 || j > l[indexM]->size) {
                printf(" ");
                continue;
            }
            printf(" %d",l[indexM]->arr[i][j]);
        }
        printf("\n");
    }
}

void displayMoveMenu(){
    printf("\t \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
    printf("\n\t               z\n");
    printf("\t  q            s           d\n\n\t n pour quitter\n");
    printf("\t \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");


}

void move(Map* l, Player* p, int* continuing) {
    displayMoveMenu();
    int input =  fgetc(stdin);
    switch (input) {
    case 's':
        if(p->x + 1 < l->size) {
            p->x += 1;
            p->orientation = left;
        }
        break;
    case 'q':
        if(p->y - 1 >= 0) {
            p->y = p->y - 1;
            p->orientation = top;
        } 
        break;
    case 'z':
        if (p->x - 1 >= 0) {
            p->x = p->x - 1;
            p->orientation = right;
        } 
        break;
    case 'd':
        if(p->y + 1 < l->size) {
            p->y += 1;
            p->orientation = down;
        }
        break;
    case 'n':
        *continuing = 0;
        break;
    }
}

void checkAround(Player p, int * indexMap, Map** list) {
    if(p->orientation == top) {
        
    }
    if(p->orientation == down) {
        
    }
    if(p->orientation == left) {
        
    }
    if(p->orientation == right) {
        
    }
}

