//
// Created by vette on 21/11/2021.
//

#include "headers/Save.h"


void Save (Player * player) {

    FILE* file = fopen("save.txt", "w+");

    if (file == NULL){
        printf("Fichier non ouvert");
    }

    fputs("===== Player =====\n",file);
    fprintf(file,"%d\n",player->level);
    fprintf(file,"%d/%d\n",player->exp,player->maxExp);
    fprintf(file,"%d/%d\n",player->currentHp,player->maxHp);
    // fprintf(file,"max Hp : %d\n",player->maxHp);
    // fprintf(file,"max exp : %d\n",player->maxExp);

    fclose(file);
}

void Resume (Player * player) {

    FILE* file = fopen("save.txt", "r");

    if (file == NULL){
        printf("Fichier non ouvert");
    }

    char line[256];
    const char * separator = "/";
    int countElement = 0;
    fgets(line, 256, file);

    while(fgets(line, 256, file)) {
        char* token = strtok (line, separator);

        while(token != NULL) {
            switch (countElement) {
                case 0 :
                    player->level = atoi(token);
                    countElement++;
                    // printf("token:%s\n",token);
                    // printf("count:%d\n",countElement);
                    break;
                case 1 :
                    player->exp = atoi(token);
                    countElement++;
                    // printf("token:%s\n",token);
                    break;
                case 2 :
                    player->maxExp = atoi(token);
                    countElement++;
                    break;
                case 3 :
                    player->currentHp = atoi(token);
                    countElement++;
                    break;
                case 4 :
                    player->maxHp = atoi(token);
                    countElement = 0;
                    break;
            }
            token = strtok (NULL, separator);
        }
    }
    fclose(file);
}