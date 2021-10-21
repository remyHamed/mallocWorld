#include "player.h"

Player* creatPlayer() {
    Player * babyPlayer = malloc(sizeof(player));
    babyPlayer->currentHp = 100;
    return babyPlayer;
}

void movePlayer(Player* p, Map * m) {
   //ANCHOR la fonction doit être dans un do while 
    char c;
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
    //ANCHOR Faire les limitation pour que le joueur ne sorte pas de la carte
}