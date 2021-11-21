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
    fprintf(file,"current Hp : %d\n",player->currentHp);
    fprintf(file,"max Hp : %d\n",player->maxHp);
    fprintf(file,"level : %d\n",player->level);
    fprintf(file,"exp : %d\n",player->exp);

    fclose(file);
}

Player * RecoverSave () {

    Player * player = initPlayer();

    FILE* file = fopen("save.txt", "r");

    if (file == NULL){
        printf("Fichier non ouvert");
    }

    char* line = malloc(sizeof(char)* 256);
    const char * separator = ":";
    int countElement = 0;
    fgets(line, 256, file);

    while(fgets(line, 256, file)) {
        char* token = strtok (line, separator);

        while(token != NULL) {
            switch (countElement) {
                case 0 :
                    countElement++;
                    break;
                case 1 :
                    player->currentHp = atoi(token);
                    countElement++;
                    break;
                case 2 :
                    countElement++;
                    break;
                case 3 :
                    player->maxHp = atoi(token);
                    countElement++;
                    break;
                case 4 :
                    countElement++;
                    break;
                case 5 :
                    player->level = atoi(token);
                    countElement++;
                    break;
                case 6 :
                    countElement++;
                    break;
                case 7 :
                    player->exp = atoi(token);
                    countElement = 0;
                    break;
            }
            token = strtok (NULL, separator);
        }
    }

    fclose(file);
    return player;
}