//
// Created by Vettese on 13/10/2021.
//
#include "Battle.h"
void choices (int *pv1, int *pv2, int choice, int *damage1) {
    if (choice == 1) {
        printf("pv2: %d to ",*pv2);
        *pv2 -= *damage1;
        printf("%d \n",*pv2);
    }
    else if (choice == 2) {
        printf("pv1: %d to ",*pv1);
        *pv1 += 50;
        printf("%d \n",*pv1);
    }
}

void Battle( int damage1, int pv1) {
    Monster * monster = init();
    printf("monster index : %d \n",monster->index);
    char currentPlayer='1';
    int choice = 0;
    srand( time( NULL ) );
    while (pv1 > 0 && monster->hp > 0) {
        if (currentPlayer == '1') {
            printf("Player turn \n");
            printf("choose a action : \n 1) attack \n 2) potion \n 3) escape \n");
            scanf("%d", &choice);
            if (choice == 3){
                int chance = rand() % 100;
                printf("%d \n",chance);
                if (chance <= 30) {
                    printf("you successfully escaped");
                    break;
                }
                else {
                    printf("you failed to escape \n");
                }
            }
            choices(&pv1, &monster->hp, choice, &damage1);
            if (monster->hp <= 0) {
                break;
            } else{
                currentPlayer = '2';
            }
        }
        if (currentPlayer == '2') {
            printf("%s turn \n",monster->name);
            printf("pv1 : %d to ",pv1);
            pv1 -= monster->damage;
            printf("%d \n",pv1);
            if (pv1 <= 0) {
                break;
            } else{
                currentPlayer = '1';
            }
        }
    }
    if (monster->hp <= 0) {
        printf("\nPlayer 1 is the winner");
    }
    if (pv1 <= 0) {
        printf("\n%s is the winner",monster->name);
    }
}