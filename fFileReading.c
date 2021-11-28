#include "headers/fFileReading.h"

void readFile(const char* pathToFile) {
    int index = 0;
    char* line;
    line = malloc(sizeof(char)* 255);
    FILE* file = fopen(pathToFile, "r");
    if (file == NULL) {
        printf("Fichier non ouvert");
    }
    while(fgets(line, 255, file)) {
        lineSpliter(line);
    }
    fclose(file);
    free(line);
}

char** lineSpliter(char * str) {
    int num = getnumberofparts(str);
    char** arr = malloc(sizeof(char*) * num);
    char* pStart;
    char* pEnd;
    int lenght = 0;
    int index = 0;
    pStart = str;
    pEnd = str;
    for (int i = 0; i < num -1; i++) {
        while (*pEnd != '|') {
            pEnd++;
        }
        *pEnd='\0';
        lenght = strlen(pStart);
        arr[index] = malloc(sizeof(char) * lenght + 1 );
        strcpy(arr[index], pStart);
        pEnd++;
        pStart = pEnd++;
        index++;
    }
    while (*pEnd != '@') {
        pEnd++;
    }
    *pEnd='\0';
    lenght = strlen(pStart);
    arr[index] = malloc(sizeof(char) * lenght + 1 );
    strcpy(arr[index], pStart);
    pStart = pEnd++;
    return arr;
}

int getnumberofparts(char * str) {
    int numOfPart = 0;
    int index = 0;
    while (str[index] != '@') {
        if(str[index] == '|') {
            numOfPart++;
        }
        index++;
    }
    numOfPart++;
    return numOfPart;
}


int countLines(char* pathToFile) {
    int index = 0;
    char* line;
    line = malloc(sizeof(char)* 255);
    FILE* file = fopen(pathToFile, "r");
    if (file == NULL) {
        printf("Fichier non ouvert");
    }
    while(fgets(line, 255, file)) {
        index++;
    }
    fclose(file);
    free(line);
    return index;
}