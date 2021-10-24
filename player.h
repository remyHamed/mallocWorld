#ifndef player_h 
#define player_h 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "map.h"

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

int playerStayInBounds(Player * p, Map* m);
int colisionChecker(Player* p, Map* m);
void movePlayer(Player* p, Map* m);
void diplayMenuForMov();  
#endif

