//
// Created by vette on 21/11/2021.
//

#include "headers/Save.h"

int CheckFile (char * filename) {
    
    FILE * file = fopen(filename, "r");
    
    if (file == NULL){
        return 0 ;
    }
    fclose(file);
    return 1;
} 

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
    fputs("===== Player =====\n",file);
    fprintf(file,"{%d}\n",player->level);
    fprintf(file,"{%d}/{%d}\n",player->exp,player->maxExp);
    fprintf(file,"{%d}/{%d}\n",player->currentHp,player->maxHp);
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
    const char * separator = "{/}";
    int countElement = 0;
    fgets(line, 256, file);
    fgets(line, 256, file);
    fgets(line, 256, file);
    while (strcmp(line,"===== Player =====\n") != 0) {
        // printf("boucle zone \n");
        switch (countElement) {
            case 0 :
                for (int j=0; j<list[0]->size ; j++) {
                    *list[0]->arr[j] = atoi(line);
                    fgets(line, 256, file);

                }
                countElement++;
                break;
            case 1 :
                fgets(line, 256, file);
                for (int j=0; j<list[1]->size ; j++) {
                    *list[1]->arr[j] = atoi(line);
                    fgets(line, 256, file);

                }
                countElement++;
                break;
            case 2 :
                fgets(line, 256, file);
                for (int j=0; j<list[2]->size ; j++) {
                    *list[2]->arr[j] = atoi(line);
                    fgets(line, 256, file);

                }
                countElement = 0;
                break;
        }
    }
    // printf("line : %s\n",line);
    while(fgets(line, 256, file)) {
        char* token = strtok (line, separator);

        while(token != NULL) {
            switch (countElement) {
                case 0 :
                    player->level = atoi(token);
                    countElement++;
                    token = strtok (line, separator);
                    break;
                case 1 :
                    player->exp = atoi(token);
                    countElement++;
                    break;
                case 2 :
                    player->maxExp = atoi(token);
                    // printf("token :%s\n",token);
                    countElement++;
                    token = strtok (line, separator);
                    break;
                case 3 :
                    player->currentHp = atoi(token);
                    // printf("token2 :%s\n",token);
                    countElement++;
                    break;
                case 4 :
                    player->maxHp = atoi(token);
                    // printf("token3 :%s\n",token);
                    countElement++;
                    break;
            }
            token = strtok (NULL, separator);
        }
    }
    fclose(file);
}

void SaveSize (int size1,int size2,int size3) {
    FILE* file = fopen("savesize.txt", "w+");

    if (file == NULL){
        printf("Fichier non ouvert");
    }    
        fprintf(file,"%d\n",size1);
        fprintf(file,"%d\n",size2);
        fprintf(file,"%d\n",size3);
    
    fclose(file);
}

int* ResumeSize () {
    FILE* file = fopen("savesize.txt", "r");

    if (file == NULL){
        printf("Fichier non ouvert");
    }

    char line[5];
    int* size =  malloc(sizeof(int)*3);
    fgets(line,5,file);
    for (int i = 0; i<4 ; i++) {
        size[i] = atoi(line);
        fgets(line,5,file);
    }
    fclose(file);
    return size;
}