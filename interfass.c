#include "interfasse.h"

void screenGame(Map** l, Player* gamer) {
    int levelIndex = 0;
    int i = gamer->x - 20;
    int j = gamer->y - 20;
    int limite = i + 40;
    int triggerI = 0;
    int triggerj = 0;

    for (; i < limite; i++) {
        for (int j = 0; j <limite; j++) {
            if(i == gamer->x && j == gamer->y) {
                printf("X");
                continue;
            }
            if(i < 0 || j < 0) {
                printf(" ");
                continue;
            }
            printf("%d",l[levelIndex]->arr[i][j]);
        }
        printf("\n");
    }
}