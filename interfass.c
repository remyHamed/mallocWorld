#include "headers/interfasse.h"

void screenGame(Map** l, Player* gamer, int indexM) {
    int x_start_window = gamer->x - 20;
    int y_start_window = gamer->y - 20;
    int x_end_window = gamer->x + 20;
    int y_end_window = gamer->y + 20;
    if(x_start_window < 0) {
        x_start_window = 0;
    }
    if(y_start_window < 0) {
        y_start_window = 0;
    }
    if(x_start_window > l[indexM]->size) {
        x_start_window = l[indexM]->size;
    }
    if(y_start_window > l[indexM]->size) {
        y_start_window = l[indexM]->size;
    }

    if(x_end_window < 0) {
        x_end_window = 0;
    }
    if(y_end_window < 0) {
        y_end_window = 0;
    }
    if(x_end_window > l[indexM]->size) {
        x_end_window = l[indexM]->size;
    }
    if(y_end_window > l[indexM]->size) {
        y_end_window = l[indexM]->size;
    }
    printf("\n");
    for (int i = x_start_window; i < x_end_window; i+= 1) {
        if(i < 0 || i > l[indexM]->size) {
            printf("\n");
            continue;
        }
        for (int j = y_start_window; j < y_end_window; j+= 1) {
            if(j < 0 || j > l[indexM]->size) {
                printf(" ");
                continue;
            }
            printf(" %d",l[indexM]->arr[i][j]);
        }
        printf("\n");
    }
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

