//
// Created by vette on 28/10/2021.
//
#include "headers/Monster.h"

Monster ** initMonster () {
    Monster** tabMonster;
    tabMonster = malloc(sizeof(Monster*)*22);
    FILE* file = fopen("items/Monster.txt", "r");
    if (file == NULL) {
        printf("Fichier non ouvert");
    } else {
        printf("\nfile is open\n");
    }
    char* line;
    line = malloc(sizeof(char)* 256);
    int index = 0;
    while(fgets(line, 256, file)) {
        tabMonster[index] = lineToStructMonster(line);
        index++;
    }
    fclose(file);
    free(line);
    return tabMonster;
}

Monster* lineToStructMonster(char* line) {
    const char * separator = "|";
    int countElement = 0;
    char* token = strtok (line, separator);
    //char * temp = malloc(sizeof(char)*256);
    //strcpy(temp, token);
    Monster* bakemono = malloc(sizeof(Monster));
    while(token != NULL) {
        switch (countElement) {
            case 0 :
                bakemono->id = atoi(token);
                countElement++;
                break;
            case 1 :
                bakemono->zone = atoi(token);
                countElement++;
                break;
            case 2 :
                bakemono->name = malloc(sizeof(char) * 256);
                strcpy(bakemono->name, token);
                countElement += 1;
                break;
            case 3 :
                bakemono->hp = atoi(token);
                countElement++;
                break;
            case 4 :
                bakemono->damage = atoi(token);
                countElement++;
                break;
            case 5 :
                bakemono->exp = atoi(token);
                countElement = 0;
                break;
        }
        token = strtok (NULL, separator);
    }
  /*  printf("id : %d\n", bakemono->id);
    printf("zone : %d\n", bakemono->zone);
    printf("name : %s\n", bakemono->name);
    printf("hp : %d\n", bakemono->hp);
    printf("damage : %d\n", bakemono->damage);
    printf("exp : %d\n\n", bakemono->exp);*/
    return bakemono;
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
    free(bakemono->name);
    free(bakemono);
    printf("ok\n");
}