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