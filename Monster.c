//
// Created by vette on 28/10/2021.
//
#include "headers/Monster.h"

Monster ** initMonster () {
    Monster** tabMonster;
    tabMonster = malloc(sizeof(Monster*)*21);
    char const* const fileName = "items/Monster.txt";
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Fichier non ouvert");
    }
    
    char* line;
    line = malloc(sizeof(char)* 256);
    int index = 0;

    while(fgets(line, 256, file)) {
        tabMonster[index] = lineToStructMonster(line);
        index++;
    }
    fclose(file);
    return tabMonster;
}

Monster* lineToStructMonster(char* line)
{
    const char * separator = "|";
    int countElement = 0;
    char* token = strtok (line, separator);
    //char * temp = malloc(sizeof(char)*256);
    //strcpy(temp, token);
    Monster* monster = malloc(sizeof(Monster));
    while(token != NULL) {
        switch (countElement) {
            case 0 :
                monster->id = atoi(token);
                countElement++;
                break;
            case 1 :
                monster->zone = atoi(token);
                countElement++;
                break;
            case 2 :
                monster->name = malloc(sizeof(char) * 256);
                strcpy(monster->name, token);
                countElement += 1;
                break;
            case 3 :
                monster->hp = atoi(token);
                countElement++;
                break;
            case 4 :
                monster->damage = atoi(token);
                countElement++;
                break;
            case 5 :
                monster->exp = atoi(token);
                countElement = 0;
                break;
        }
        token = strtok (NULL, separator);
    }
    return monster;
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