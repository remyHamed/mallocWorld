#include "headers/Monster.h"

Monster ** initMonster () {
    char* line;
    char** dataFromLine;
    int index = 0;
    Monster** tabMonster;
    int numOfMonsterModel = countLines("items/Monster.txt");
    line = malloc(sizeof(char)* 256);
    tabMonster = malloc(sizeof(Monster*) * numOfMonsterModel);
    FILE* file = fopen("items/Monster.txt", "r");
    
    if (file == NULL) {
        printf("Fichier non ouvert");
    } else {
        printf("\nfile isd open\n");
    }
 
    while(fgets(line, 256, file)) {
        dataFromLine = lineSpliter(line);
        tabMonster[index] = setMonster(dataFromLine);
        for(int i = 0; i < 6; i++) {
            free(dataFromLine[i]);
        }
        index++;
    }
    free(dataFromLine);
    fclose(file);
    free(line);
    return tabMonster;
}

Monster* setMonster(char** dataOfMonster) {
    Monster* bakemono = malloc(sizeof(Monster));
   
   bakemono->id = atoi(dataOfMonster[0]);
    bakemono->zone = atoi(dataOfMonster[1]);
    bakemono->name = malloc(sizeof(char) * 256);
    strcpy(bakemono->name, dataOfMonster[2]);
    bakemono->hp = atoi(dataOfMonster[3]);
    bakemono->damage = atoi(dataOfMonster[4]);
    bakemono->exp = atoi(dataOfMonster[5]);
    printf("Nom : %s\n", bakemono->name);
    printf("Damage : %d\n\n", bakemono->damage);
    printf("Nom : %s\n", bakemono->name);
    printf("Damage : %d\n\n", bakemono->damage);
    printf("Nom : %s\n", bakemono->name);
    printf("Damage : %d\n\n", bakemono->damage);
    return bakemono;
    
  /*  printf("id : %d\n", bakemono->id);
    printf("zone : %d\n", bakemono->zone);
    printf("name : %s\n", bakemono->name);
    printf("hp : %d\n", bakemono->hp);
    printf("damage : %d\n", bakemono->damage);
    printf("exp : %d\n\n", bakemono->exp);*/
}

void printMonster(Monster** tabMonster)
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

Monster * RandomMonster (Monster ** tabMonster) {
 srand( time( NULL ) );
 int cpt =0;

 int id = rand() % 20;
 
 return tabMonster[id];

}

void freeMonster(Monster * bakemono) {
    free(bakemono->name );
    free(bakemono);
    printf("ok\n");
}


Monster **genMonsterarrLevel(int indexMap, int numIdMonsterMin, int numIdMonsterMax, Monster **model, Map *m) {
    m->numOfMonster = m->size / 4;
    int* arrRandPosition;
    Monster** arrMonster = malloc(sizeof(Monster*) * m->numOfMonster);
    printf("nom of monster  = %d\n",m->numOfMonster);
    for (int i = 0; i < m->numOfMonster; i++) {
        printf(" i = %d\n",i);
        arrMonster[i] = malloc(sizeof(Monster));
        arrMonster[i]->id = genrandomNumber(numIdMonsterMin, numIdMonsterMax);
        printf("51\n");
        arrMonster[i]->zone = indexMap;
        printf("52\n");
        arrMonster[i]->name = malloc(sizeof(char) * 255);
        printf("arrMonster[i]->id = %d\n", arrMonster[i]->id);
        strcpy(arrMonster[i]->name, model[arrMonster[i]->id]->name);
        arrMonster[i]->hp = model[arrMonster[i]->id]->hp;
        printf("53\n");
        arrMonster[i]->damage = model[arrMonster[i]->id]->damage;
        arrMonster[i]->exp = model[arrMonster[i]->id]->exp;
        arrRandPosition = genrandomPosition(m->size - 1);
        arrMonster[i]->x = arrRandPosition[0];
        arrMonster[i]->y = arrRandPosition[1];
        arrMonster[i]->status = 15;
        arrMonster[i]->isAlive = 1;
        free(arrRandPosition);
        printf("arrMonster[i]->id = %d\n",arrMonster[i]->id);
        printf("id : %d\n", arrMonster[i]->id);
        printf("zone : %d\n", arrMonster[i]->zone);
        printf("name : %s\n", arrMonster[i]->name);
        printf("hp : %d\n", arrMonster[i]->hp);
        printf("damage : %d\n", arrMonster[i]->damage);
        printf("exp : %d\n\n", arrMonster[i]->exp);
        printf("x : %d\n", arrMonster[i]->x);
        printf("y : %d\n\n", arrMonster[i]->y);
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
    printf(" nombre de monstre = %d\n",m->numOfMonster);
    for (int i = 0; i < m->numOfMonster; i++) {
        xpos = m->monstertab[i]->x;
        ypos = m->monstertab[i]->y;
        printf("----////////////----\n");
        if(m->arr[xpos][ypos] == 0) {
            m->arr[xpos][ypos] = m->monstertab[i]->id;
        } else {
            while(m->arr[xpos][ypos] != 0) {
                arrRandPosition = genrandomPosition(m->size-1);
                xpos = arrRandPosition[0];
                xpos = arrRandPosition[1];
                free(arrRandPosition);
            }    
        }
    }
}