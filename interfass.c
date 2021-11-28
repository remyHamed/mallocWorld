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
    printf("\t //////////////////////////// \n");
    printf("\t               z\n");
    printf("\t  q            s           d\n");
    printf("\t //////////////////////////// \n");
}

void move(Map* l, Player* p, int* continuing, int * index, int* input, int* temp) {
    if (*input != '\n')
        displayMoveMenu();
    *input =  fgetc(stdin);
    if (*input != '\n') {
        // *input = *temp;
        switch (*input) {
            case 's':
                p->orientation = 4;
                if(!isMovable(l, p, index, p->x + 1, p->y)) {
                    break;
                }
                if(p->x + 1 < l->size) {
                    l->arr[p->x][p->y] = 0;
                    p->x += 1;
                    l->arr[p->x][p->y] = 1;
                }
                break;
            case 'q':
                p->orientation = 2;
                if(!isMovable(l, p, index, p->x, p->y - 1)) {
                    break;
                }
                if(p->y - 1 >= 0) {
                    l->arr[p->x][p->y] = 0;
                    p->y = p->y - 1;
                    l->arr[p->x][p->y] = 1;
                } 
                break;
            case 'z':
                p->orientation = 1;
                if(!isMovable(l, p, index, p->x - 1, p->y)) {
                    break;
                }
                if (p->x - 1 >= 0) {
                    l->arr[p->x][p->y] = 0;
                    p->x = p->x - 1;
                    l->arr[p->x][p->y] = 1;
                } 
                break;
            case 'd':
                p->orientation = 3;
                if(!isMovable(l, p, index, p->x, p->y + 1)) {
                    break;
                }
                if(p->y + 1 < l->size) {
                    l->arr[p->x][p->y] = 0;
                    p->y += 1;
                    l->arr[p->x][p->y] = 1;
                }
                break;
            case 'n':
                *continuing = 0;
                break;
            default:
                printf("mauvaise saisie recommencez\n");
                break;
        }
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

int isMovable(Map* l,Player * p, int* index, int x, int y) {
   if(x < 0) {
        return 0;
    }
    if(x >= l->size) {
        return 0;
    }
    if(y < 0) {
        return 0;
    }
    if(y >= l->size) {
        return 0;
    }
    if(l->arr[x][y] == -3) {
        return 0;
    }
    return 1;
}

int gateMenu(Map* m, Player* p, int* index) {
    printf("\nindex dans gate menu = %d\n", *index);
    int loop = 1;
    char userInput[250];
    int a = 0;
    if(*index == 0) {
        if(m->levelLimit < p->level) {
            while (loop) {
                printf("\t Voulez vous allez au niveau superieur?\n\t 1 oui \n\t 2 non \n");
                ///fflush(stdin);
                setbuf(stdin, NULL);
                fgets(userInput, 250, stdin);
                //a =getc(stdin);
                a = fgetc(stdin);
                printf("\n user input -> %d\n",a);
                switch(a) {
                    case '1':
                        *index += 1;
                        printf("\nindex après incrémentation = %d\n", *index);
                        loop = 0;
                        break;
                    case '2':
                        break;
                    default:
                        printf("\n selection la touche 1 ou 2\n");
                        break;
                }
                return *index;
            }
        } else {
            printf("\n Niveau %d requi pour le protail\n ", m->levelLimit);
            return *index;
        }
    }
    if(*index == 1) {
        if(m->levelLimit <= p->level) {
            printf("\t Voulez vous changer de niveau?\n");
            while (loop) {
                printf("\t 1 niveau superieur \n\t 2 niveau inferieur \n \t 3 rester là\n");
                fgets(userInput, 250, stdin);
                switch(userInput[0]) {
                    case '1':
                        *index += 1;
                        loop = 0;
                        break;
                    case '2':
                        *index = *index - 1;
                        loop = 0;
                        break;
                    case '3':
                        loop = 0;
                        break;
                    default:
                        printf("\n selection la touche 1, 2 ou 3\n");
                        break;
                }
                return *index;
            }
        } else {
            printf("\n Niveau %d requi pour aller au niveau supérieur\n ", m->levelLimit);
            printf("\t Voulez vous allez au niveau inferieur ?\n\t 1 oui \n\t 2 non \n");
        }
        

    } 
    if(*index == 2) {
            while (loop) {
                printf("\t Voulez vous allez au niveau inferieur ?\n");
                printf("\t 1 oui \n\t 2 non \n");
                fgets(userInput, 250, stdin);
                switch(userInput[0]) {
                    case '1':
                        *index = *index - 1;
                        loop = 0;
                        break;
                    case '2':
                        loop = 0;
                        break;
                    default:
                        printf("\n selection la touche 1, 2 ou 3\n");
                        break;
                }
                return *index;
            }
    }
}