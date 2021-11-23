//
// Created by vette on 21/11/2021.
//

#include "headers/Save.h"


void Save (Player * player, Map ** list) {

    FILE* file = fopen("save.txt", "w+");

    if (file == NULL){
        printf("Fichier non ouvert");
    }

    fputs("===== Map =====\n",file);
    for (int i=0; i<3 ; i++) {
        fprintf(file,"--- zone %d ---",i+1);
        for (int j=0; j<list[i]->size ; j++) {
            fputs("\n",file);
            for (int k=0; k<list[i]->size ; k++) {
                fprintf(file,"%d ",list[i]->arr[j][k]);
            }
        }
        fputs("\n",file);
    }

    // fputs("--- zone 1 ---\n",file);
    // fputs("--- zone 2 ---\n",file);
    // fputs("--- zone 3 ---\n",file);
    fputs("===== Player =====\n",file);
    fprintf(file,"%d\n",player->level);
    fprintf(file,"%d/%d\n",player->exp,player->maxExp);
    fprintf(file,"%d/%d\n",player->currentHp,player->maxHp);
    // fprintf(file,"max Hp : %d\n",player->maxHp);
    // fprintf(file,"max exp : %d\n",player->maxExp);
    fputs("--- Inventory ---\n",file);
    fputs("--- Storage ---\n",file);

    fclose(file);
}

void Resume (Player * player, Map ** list) {

    FILE* file = fopen("save.txt", "r");

    if (file == NULL){
        printf("Fichier non ouvert");
    }

    char line[256];
    const char * separator = "/";
    int countElement = 0;
    fgets(line, 256, file);
    fgets(line, 256, file);

    while(fgets(line, 256, file)) {
        char* token = strtok (line, separator);

        while(token != NULL) {
            switch (countElement) {
                case 0 :
                    for (int j=0; j<50 ; j++) {
                        *list[0]->arr[j] = atoi(token);
                        fgets(line, 256, file);

                    }
                    break;
            //     case 1 :
            //         player->exp = atoi(token);
            //         countElement++;
            //         // printf("token:%s\n",token);
            //         break;
            //     case 2 :
            //         player->maxExp = atoi(token);
            //         countElement++;
            //         break;
            //     case 3 :
            //         player->currentHp = atoi(token);
            //         countElement++;
            //         break;
            //     case 4 :
            //         player->maxHp = atoi(token);
            //         countElement = 0;
            //         break;
            //     case 5 :
            //         player->level = atoi(token);
            //         countElement++;
            //         // printf("token:%s\n",token);
            //         // printf("count:%d\n",countElement);
            //         break;
            //     case 6 :
            //         player->exp = atoi(token);
            //         countElement++;
            //         // printf("token:%s\n",token);
            //         break;
            //     case 7 :
            //         player->maxExp = atoi(token);
            //         countElement++;
            //         break;
            //     case 8 :
            //         player->currentHp = atoi(token);
            //         countElement++;
            //         break;
            //     case 9 :
            //         player->maxHp = atoi(token);
            //         countElement = 0;
            //         break;
            //     case 10 :
            //         player->level = atoi(token);
            //         countElement++;
            //         // printf("token:%s\n",token);
            //         // printf("count:%d\n",countElement);
            //         break;
            //     case 11 :
            //         player->exp = atoi(token);
            //         countElement++;
            //         // printf("token:%s\n",token);
            //         break;
            //     case 12 :
            //         player->maxExp = atoi(token);
            //         countElement++;
            //         break;
            //     case 13 :
            //         player->currentHp = atoi(token);
            //         countElement++;
            //         break;
            //     case 14 :
            //         player->maxHp = atoi(token);
            //         countElement = 0;
            //         break;
            }
            token = strtok (NULL, separator);
        }
    }
    fclose(file);
}