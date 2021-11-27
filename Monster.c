//
// Created by vette on 28/10/2021.
//
#include "headers/Monster.h"

Monster **initMonster()
{
    Monster **tabMonster;
    tabMonster = malloc(sizeof(Monster *) * 22); //TODO faire une fonctio qui compte le nombre de ligne
    FILE *file = fopen("items/Monster.txt", "r");
    if (file == NULL)
    {
        printf("Fichier non ouvert");
    }
    char *line;
    line = malloc(sizeof(char) * 256);
    int index = 0;
    while (fgets(line, 256, file))
    {
        tabMonster[index] = lineToStructMonster(line);
        index++;
    }
    fclose(file);
    return tabMonster;
}

Monster *lineToStructMonster(char *line)
{
    const char *separator = "|";
    int countElement = 0;
    char *token = strtok(line, separator);
    //char * temp = malloc(sizeof(char)*256);
    //strcpy(temp, token);
    Monster *monster = malloc(sizeof(Monster));
    while (token != NULL)
    {
        switch (countElement)
        {
        case 0:
            monster->id = atoi(token);
            countElement++;
            break;
        case 1:
            monster->zone = atoi(token);
            countElement++;
            break;
        case 2:
            monster->name = malloc(sizeof(char) * 256);
            strcpy(monster->name, token);
            countElement += 1;
            break;
        case 3:
            monster->hp = atoi(token);
            countElement++;
            break;
        case 4:
            monster->damage = atoi(token);
            countElement++;
            break;
        case 5:
            monster->exp = atoi(token);
            countElement = 0;
            break;
        }
        token = strtok(NULL, separator);
    }
    return monster;
}

void printMonster(Monster **tabMonster)
{
    for (int i = 0; i < 21; i++)
    {
        printf("id : %d\n", tabMonster[i]->id);
        printf("zone : %d\n", tabMonster[i]->zone);
        printf("name : %s\n", tabMonster[i]->name);
        printf("hp : %d\n", tabMonster[i]->hp);
        printf("damage : %d\n", tabMonster[i]->damage);
        printf("exp : %d\n\n", tabMonster[i]->exp);
    }
}

Monster *RandomMonster(Monster **tabMonster)
{
    srand(time(NULL));
    int cpt = 0;

    int id = rand() % 20;

    return tabMonster[id];
}

Monster **genMonsterarrLevel(int indexMap, int numIdMonsterMin, int numIdMonsterMax, Monster **model, Map *m) {
    m->numOfMonster = m->size / 4;
    int *arrRandPosition;
    Monster **arrMonster = malloc(sizeof(Monster *) * m->numOfMonster);
    printf("nb of monster  = %d\n",m->numOfMonster);
    for (int i = 0; i < m->numOfMonster-1; i++)
    {
        //printf("error is not hear i = %d\n",i);
        arrMonster[i] = malloc(sizeof(Monster));
        arrMonster[i]->id = genrandomNumber(numIdMonsterMin, numIdMonsterMax);
        //printf("arrMonster[i]->id = %d\n",arrMonster[i]->id);
        arrMonster[i]->zone = indexMap;
        arrMonster[i]->name = malloc(sizeof(char*) * 255);
        strcpy(arrMonster[i]->name, model[arrMonster[i]->id]->name);
        arrMonster[i]->hp = model[arrMonster[i]->id]->hp;
        arrMonster[i]->damage = model[arrMonster[i]->id]->damage;
        arrMonster[i]->exp = model[arrMonster[i]->id]->exp;
        arrRandPosition = genrandomPosition(m->size-1);
        arrMonster[i]->x = arrRandPosition[0];
        printf("arrRandPosition 1 = %d\n",arrRandPosition[0]);
        arrMonster[i]->y = arrRandPosition[1];
        printf("arrRandPosition 2 = %d\n",arrRandPosition[1]);
        arrMonster[i]->status = 15;
        arrMonster[i]->isAlive = 1;
        free(arrRandPosition);
    }
    //TODO mettre la fonction qui init les postions du monstre sur le tableau de la carte
    return arrMonster;
}
//TODO
//fonction generation des montres sur la map

void putMonsterOnMap(Map *m) {
    int xpos = 0;
    int ypos = 0;
    int *arrRandPosition;
    
    for (int i = 0; i < m->numOfMonster; i++) {
        xpos = m->monstertab[i]->x;
        xpos = m->monstertab[i]->y;
        if(m->arr[xpos][ypos] == 0) {
            m->arr[xpos][ypos] = m->monstertab[i]->id;
        } else {
            while(m->arr[xpos][ypos] != 0) {
                arrRandPosition = genrandomPosition(m->size);
                xpos = arrRandPosition[0];
                xpos = arrRandPosition[1];
                free(arrRandPosition);
            }    
        }
    }
}