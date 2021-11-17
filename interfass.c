#include "headers/interfasse.h"

void screenGame(Map** l, Player* gamer, int indexM) {

    /*for (int i = gamer->x - 20 ; i < gamer->x + 20; i+= 1) {
        if(i < 0 || i >= l[indexM]->size) {
            printf("\n");
            continue;
        }
        for (int j = gamer->y - 20; j < gamer->y + 20; j+= 1) {
            if(i == gamer->x && j == gamer->y) {
                printf(" X");
                continue;
            }
            if(j < 0 || j >= l[indexM]->size) {
                printf(" ");
                continue;
            }
            printf(" %d",l[indexM]->arr[i][j]);
        }
        printf("\n");
    }*/
    printf("\n ");
    for(int i  = 0; i < l[indexM]->size; i++) {
        printf("__");
    }
    printf("\n");
    for(int i  = 0; i < l[indexM]->size; i++) {
        for(int j  = 0; j < l[indexM]->size; j++) {
            if(j == 0) {
                printf("|");
            }
            printf(" %d",l[indexM]->arr[i][j]);
        }
        printf("|\n");
    }
    for(int i  = 0; i < l[indexM]->size; i++) {
        printf("--");
    }
    printf("\n");
}

void displayMoveMenu() {
    printf("\t \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
    printf("\n\t               z\n");
    printf("\t  q            s           d\n");
    printf("\t \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
}

void move(Map* l, Player* p, int* continuing) {
    displayMoveMenu();
    int input =  fgetc(stdin);
    switch (input) {
    case 's':
        if(p->x + 1 < l->size) {
            l->arr[p->x][p->y] = 0;
            p->x += 1;
            p->orientation = 4;
            l->arr[p->x][p->y] = 1;
        }
        break;
    case 'q':
        if(p->y - 1 >= 0) {
            l->arr[p->x][p->y] = 0;
            p->y = p->y - 1;
            p->orientation = 2;
            l->arr[p->x][p->y] = 1;
        } 
        break;
    case 'z':
        if (p->x - 1 >= 0) {
            l->arr[p->x][p->y] = 0;
            p->x = p->x - 1;
            p->orientation = 1;
            l->arr[p->x][p->y] = 1;
        } 
        break;
    case 'd':
        if(p->y + 1 < l->size) {
            l->arr[p->x][p->y] = 0;
            p->y += 1;
            p->orientation = 3;
            l->arr[p->x][p->y] = 1;
        }
        break;
    case 'n':
        *continuing = 0;
        break;
    }
}

