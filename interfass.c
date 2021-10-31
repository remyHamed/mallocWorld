#include "interfasse.h"

void screenGame(Map** l, Player* gamer) {
    int levelIndex = 0;
    for (int i = gamer->x - 20 ; i < gamer->x + 20; i+= 1) {
        if(i < 0 || i > i > l[levelIndex]->size) {
            printf("\n");
            continue;
        }
        for (int j = gamer->y - 20; j < gamer->y + 20; j+= 1) {
            if(i == gamer->x && j == gamer->y) {
                printf("X");
                continue;
            }
            if(j < 0 || j > l[levelIndex]->size) {
                printf(" ");
                continue;
            }
            printf("%d",l[levelIndex]->arr[i][j]);
        }
        printf("\n");
    }
}