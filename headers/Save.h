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
int CheckFile (char * filename);
void Save (Player * player, Map ** list);
void Resume (Player * player, Map ** list);
void SaveSize (int size1,int size2,int size3);
int* ResumeSize ();
#endif //MALLOCWORLD_SAVE_H

