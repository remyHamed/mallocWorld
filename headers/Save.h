//
// Created by vette on 21/11/2021.
//

#ifndef MALLOCWORLD_SAVE_H
#define MALLOCWORLD_SAVE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Player.h"
#include "fmap.h"

int CheckFile (char *);
void Save (Player *, Map **);
void Resume (Player *, Map**);
void SaveSize (int ,int ,int );
int* ResumeSize ();


#endif //MALLOCWORLD_SAVE_H
