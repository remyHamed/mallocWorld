#include "headers/interfasse.h"

void screenGame(Map** l, Player* gamer, int indexM) {
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

int meneGeneral(){
    int live = 1;
    char userInput[250];
    while (live) {
        printf("\n \t \t MENU \n\t1--- NEW GAME\n\t2--- CONTINUE\n\t3---  QUIT\n");
        fgets( userInput, 250, stdin);
        switch(userInput[0]) {
            case '1':
                return 1;
                break;
            case '2':
                return 2;
                break;
            case '3':
                return 3;
                break;
            default:
                printf("\n selection la touche 1 , 2 ou 3\n");
                break;
        }
    }
}

