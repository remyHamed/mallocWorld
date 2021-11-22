//
// Created by Vettese on 13/10/2021.
//
#include "headers/Battle.h"

void choices (Player * player, Monster * monster,Weapons * weapon, int *choice) {
    Heals ** tabheal = initHeals();
    
    if (*choice == 1) {
        printf("monster pv: %d to ",monster->hp);
        monster->hp -= weapon->damage;
        printf("%d \n\n",monster->hp);
        weapon->durability-= 1;
    }
    else if (*choice == 2) {
        int id = 0;
        if (player->currentHp != player->maxHp) {
            printf("1) potion 1 : 30pv\n2) potion 2 : 80pv\n3) potion 3 : 200pv\n");
            scanf("%d", &id);
            id--;
            if (id < 3 && id >= 0) {
                printf("player pv: %d/%d to ",player->currentHp,player->maxHp);
                if (player->currentHp+tabheal[id]->heal > player->maxHp) {
                    int restepv = player->maxHp - player->currentHp;
                    player->currentHp += restepv;
                }else {
                    player->currentHp += tabheal[id]->heal;
                }
                printf("%d/%d \n\n",player->currentHp,player->maxHp);
            }else {
                printf("wrong choice\nretry:\n");
                choices (player,monster,weapon,choice);
            }
        }else {
            if (*choice != 3) {
                printf("You can't use it\nchoose another action :\n");
                scanf("%d", choice);
                choices (player,monster,weapon,choice);
            }
        }
    }
    else {
        if (*choice != 3) {
            printf("wrong choice\nretry:\n");
            scanf("%d", choice);
            choices (player,monster,weapon,choice);
        }
    }
    free(tabheal);
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
            printf("durability : %d\n",weapon->durability);
            printf("choose a action : \n 1) attack \n 2) potion \n 3) escape \n");
            scanf("%d", &choice);
            choices(player, monster, weapon, &choice);
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
            printf("Player pv : %d/%d to ",player->currentHp,player->maxHp);
            player->currentHp -= monster->damage - reducDamage;
            printf("%d/%d \n\n",player->currentHp,player->maxHp);
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
        printf("\nplayer gain %d and have %d/%d \n",monster->exp,player->exp,player->maxExp);
        printf("current hp : %d\n",player->currentHp);
        if (player->exp >= player->maxExp) {
            Leveling(player);
            printf("lvl : %d\ncurrent hp : %d max hp : %d\n\n",player->level,player->currentHp,player->maxHp);
        }
    }
    if (player->currentHp <= 0) {
        printf("\n%s is the winner\n",monster->name);
    }
}