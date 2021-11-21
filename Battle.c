//
// Created by Vettese on 13/10/2021.
//
#include "headers/Battle.h"

void choices (int *pv1, int *pv2, int *pvMax, int *choice, int *damage1) {
    Heals ** heal = initHeals();
    if (*choice == 1) {
        printf("monster pv: %d to ",*pv2);
        *pv2 -= *damage1;
        printf("%d \n\n",*pv2);
    }
    else if (*choice == 2) {
        int id = 0;
        if (*pv1 != *pvMax) {
            printf("1) potion 1 : 30pv\n2) potion 2 : 80pv\n3) potion 3 : 200pv\n");
            scanf("%d", &id);
            id--;
            if (id <= 3 && id >= 0) {
                printf("player pv: %d to ",*pv1);
                if (*pv1+heal[id]->heal > *pvMax) {
                    int restepv = *pvMax - *pv1;
                    *pv1 += restepv;
                }else {
                    *pv1 += heal[id]->heal;
                }
                printf("%d \n\n",*pv1);
            }else {
                printf("wrong choice\nretry:\n");
                choices(pv1, pv2, pvMax, choice, damage1);
            }
        }else {
            if (*choice != 3) {
                printf("You can't use it\nchoose another action :\n");
                scanf("%d", choice);
                choices(pv1, pv2, pvMax, choice, damage1);
            }
        }
    }
    else {
        if (*choice != 3) {
            printf("wrong choice\nretry:\n");
            scanf("%d", choice);
            choices(pv1, pv2, pvMax, choice, damage1);
        }
    }
}

void Battle(Player *player, Monster ** tabmonster, Weapons ** tabweapon, Armors ** tabarmor) {
    Monster * monster = RandomMonster(tabmonster);
    Weapons * weapon = tabweapon[0];
    Armors * armor = tabarmor[0];
    printf("monster name : %s \n",monster->name);
    char currentPlayer='1';
    int reducDamage = (armor->resDamage * monster->damage) /100;
    int choice = 0;
    srand( time( NULL ) );
    while (player->currentHp > 0 && monster->hp > 0) {
        if (currentPlayer == '1') {
            printf("Player turn \n");
            printf("choose a action : \n 1) attack \n 2) potion \n 3) escape \n");
            scanf("%d", &choice);
            choices(&player->currentHp, &monster->hp, &player->maxHp, &choice, &weapon->damage);
            if (choice == 3){
                int chance = rand() % 100;
                printf("%d \n",chance);
                if (chance <= 30) {
                    printf("you successfully escaped\n\n");
                    break;
                }
                else {
                    printf("you failed to escape \n");
                }
            }
            if (monster->hp <= 0) {
                break;
            } else{
                currentPlayer = '2';
            }
        }
        if (currentPlayer == '2') {
            printf("%s turn \n",monster->name);
            printf("Player pv : %d to ",player->currentHp);
            player->currentHp -= monster->damage - reducDamage;
            printf("%d \n\n",player->currentHp);
            if (player->currentHp <= 0) {
                break;
            } else{
                currentPlayer = '1';
            }
        }
    }
    if (monster->hp <= 0) {
        printf("\nPlayer is the winner");
        player->exp += monster->exp;
        printf("\nplayer gain %d and have %d \n",monster->exp,player->exp);
        printf("current hp : %d\n",player->currentHp);
        Leveling(player);
        printf("lvl : %d\nhp max : %d current hp : %d\n\n",player->level,player->maxHp,player->currentHp);
    }
    if (player->currentHp <= 0) {
        printf("\n%s is the winner\n",monster->name);
    }
}