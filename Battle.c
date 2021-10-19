//
// Created by vette on 13/10/2021.
//
#include "Battle.h"

void Battle(int damage1, int pv1, int damage2, int pv2) {
    char currentPlayer;
    if (damage1 > damage2) {
        currentPlayer = '1';
        printf("pv2 : %d to ",pv2);
        pv2 -= damage1;
        printf("%d (%c) \n",pv2,currentPlayer);
        currentPlayer = '2';
        while (pv1 > 0 && pv2 > 0) {
            if (currentPlayer == '1') {
                printf("pv2 : %d to ",pv2);
                pv2 -= damage1;
                printf("%d (%c) \n",pv2,currentPlayer);
                if (pv2 <= 0) {
                    break;
                } else{
                    currentPlayer = '2';
                }            }
            if (currentPlayer == '2') {
                printf("pv1 : %d to ",pv1);
                pv1 -= damage2;
                printf("%d (%c) \n",pv1,currentPlayer);
                if (pv2 <= 0) {
                    break;
                } else{
                    currentPlayer = '1';
                }            }
        }
    } else {
        currentPlayer = '2';
        printf("pv1 : %d to ",pv1);
        pv1 -= damage2;
        printf("%d (%c) \n",pv1,currentPlayer);
        currentPlayer = '1';
        while (pv1 > 0 && pv2 > 0) {
            if (currentPlayer == '1') {
                printf("pv2 : %d to ",pv2);
                pv2 -= damage1;
                printf("%d (%c) \n",pv2,currentPlayer);
                if (pv2 <= 0) {
                    break;
                } else{
                    currentPlayer = '2';
                }
            }
            if (currentPlayer == '2') {
                printf("pv1 : %d to ",pv1);
                pv1 -= damage2;
                printf("%d (%c) \n",pv1,currentPlayer);
                if (pv2 <= 0) {
                    break;
                } else{
                    currentPlayer = '1';
                }            }
        }
    }
    if (pv1 > 0) {
        printf("\nPlayer 1 is the winner");
    }
    if (pv2 > 0) {
        printf("\nPlayer 2 is the winner");
    }
}