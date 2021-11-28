//
// Created by Vettese on 13/10/2021.
//
#include "headers/Battle.h"

void selectActions(Player* plyr, Monster* mnstr, Weapons* arme, int* choice) {

    Heals **tabheal = initHeals();
    int next = 1;
    int id = 0;
    do {
        setbuf(stdin, NULL);
        *choice = fgetc(stdin);
        if(*choice == '\n')
            continue;
        
        switch (*choice){
            case '1':
                printf("mnstr pv: %d to ", mnstr->hp);
                mnstr->hp -= arme->damage;
                printf("%d \n\n", mnstr->hp);
                arme->durability -= 1;
                next = 0;
                break;

            case '2':
                if (plyr->currentHp != plyr->maxHp) {
                    printf("your are full hp\n");
                    break;
                }
                printf("1) potion 1 : 30pv\n2) potion 2 : 80pv\n3) potion 3 : 200pv\n");
                setbuf(stdin, NULL);
                id = fgetc(stdin);
                id--;
                if (id < 3 && id >= 0) {
                    printf("plyr pv: %d/%d to ", plyr->currentHp, plyr->maxHp);
                    if (plyr->currentHp + tabheal[id]->heal > plyr->maxHp){
                        int restepv = plyr->maxHp - plyr->currentHp;
                        plyr->currentHp += restepv;
                    } else {
                        plyr->currentHp += tabheal[id]->heal;
                    }
                    printf("%d/%d \n\n", plyr->currentHp, plyr->maxHp);
                    next = 0;
                    break;
                } else {
                    printf("1wrong choice\nretry:\n");
                    break;
                }
                break;
            default:
                printf("wrong choice\nretry:\n");
                *choice = 0;
                break;
            }

    } while (next);
    free(tabheal);
}

void Battle(Player *plyr, Monster *mnstr, Weapons *arme, Armors *armor, int *gameContinue, Map *m) {

    printf("mnstr name : %s \n", mnstr->name);
    char currentPlayer = '1';
    int reducDamage = (armor->resDamage * mnstr->damage) / 100;
    int choice = 0;
    srand(time(NULL));
    while (plyr->currentHp > 0 && mnstr->hp > 0) {
        
        if(currentPlayer == '1') {
            printf("Player turn \n");
            printf("durability : %d\n", arme->durability);
            printf("choose a action : \n 1) attack \n 2) potion \n 3) escape \n");
            //fflush(stdin);
            //__fpurge(stdin);
            selectActions(plyr, mnstr, arme, &choice);
            if(choice == 3) {
                int chance = rand() % 100;
                printf("%d \n", chance);
                if (chance <= 30)
                {
                    printf("you successfully escaped\n\n");
                    break;
                }
                else
                {
                    printf("you failed to escape \n");
                }
            }

            if (mnstr->hp <= 0)
            {
                break;
            }
            else
            {
                currentPlayer = '2';
            }
        }
        if (currentPlayer == '2') {
            printf("%s turn \n", mnstr->name);
            printf("Player pv : %d/%d to ", plyr->currentHp, plyr->maxHp);
            plyr->currentHp -= mnstr->damage - reducDamage;
            printf("%d/%d \n\n", plyr->currentHp, plyr->maxHp);
            if (plyr->currentHp <= 0)
            {
                break;
            }
            else
            {
                currentPlayer = '1';
            }
        }
        choice = 0;
    }
    if (mnstr->hp <= 0)
    {
        printf("\nPlayer is the winner");
        plyr->exp += mnstr->exp;
        printf("\nplyr gain %d and have %d/%d \n", mnstr->exp, plyr->exp, plyr->maxExp);
        printf("current hp : %d\n", plyr->currentHp);
        if (plyr->exp >= plyr->maxExp)
        {
            printf("\nplyr exp  = %d\n", plyr->exp);
            Leveling(plyr);
            printf("lvl : %d\ncurrent hp : %d max hp : %d\n\n", plyr->level, plyr->currentHp, plyr->maxHp);
        }
        mnstr->isAlive = 0;
        m->arr[mnstr->x][mnstr->y] = 0;
        mnstr->status = 0;
    }
    if (plyr->currentHp <= 0)
    {
        printf("\n%s is the winner\n", mnstr->name);
        *gameContinue = 0;
    }
}