#include "player.h"

Player* creatPlayer() {
    Player * babyPlayer = malloc(sizeof(Player));
    babyPlayer->currentHp = 100;
    babyPlayer->y_position = 0;
    babyPlayer->x_position = 0;
    return babyPlayer;
}

void diplayMenuForMov(){
    printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
    printf("z = haut\t\ts = bas\n");
    printf("q = gauche\t\td = droite\n");
    printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
}
void movePlayer(Player* p, Map* m) {
   //ANCHOR la fonction doit être dans un do while 
    char c;
    int oldPosition[2] = {p->x_position,p->y_position};
    c = getc(stdin);
    switch (c) {
        case 'z':
            p->x_position += 1; 
            break;
        case 'q':
            p->y_position -= 1; 
            break;
        case 's':
            p->x_position -= 1; 
            break;
        case 'd':
            p->y_position += 1; 
            break;
        default:
            printf("\n you should type z,q,s,d\n");
            break;
    }
    if(!playerStayInBounds(p,m)) {
        p->x_position = oldPosition[0];
        p->y_position = oldPosition[1];
    }
    if(!colisionChecker(p,m)) {
        p->x_position = oldPosition[0];
        p->y_position = oldPosition[1];
    }
}

int playerStayInBounds(Player * p, Map* m) {
    if(p->x_position > m->size) {
        return 0;
    }
    if(p->x_position < 0) {
        return 0;
    }
    if(p->y_position > m->size) {
        return 0;
    }
    if(p->x_position < 0) {
        return 0;
    }
    return 1;
}

int colisionChecker(Player* p, Map* m) {
    int x = p->x_position;
    int y = p->y_position;
    if(m->gird[x][y] != 0) {
        return 0;
    }
    return 1;
}