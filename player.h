#ifndef player_h 
#define player_h 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
struct Player {
    int currentHp;
    int maxHp;
    int x_position;
    int y_position;
    int exp;
    int level;
    //inventory JE NE SAIS PAS ENCORE DE QUEL TYPE SERA L'INVENTAIRE
    // soit on fait un tableau qui peut contenir les objets
    //
};
typedef struct Player Player;  
#endif

