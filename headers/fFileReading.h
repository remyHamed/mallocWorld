#ifndef fFileReading_h
#define fFileReading_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(const char* pathToFile);
char** lineSpliter(char * str);
int getnumberofparts(char * str);
int countLines(char* pathToFile);

#endif