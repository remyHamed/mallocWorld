#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "map.h"
#include "player.h"
#include "craft.h"
#include "tools.h"
#include "weapons.h"
#include "ressourcesCraft.h"
#include "heals.h"
#include "armor.h"

int main(int argc, char ** argv) 
{

    ListeCraft* listeC = initCraft();
    printListeCraft(listeC);
    ListeHeals* listeH = initHeals();
    printListeHeals(listeH);
    ListeTools* listeT = initTools();
    printListeHeals(listeT);
    ListeWeapons* listeW = initWeapons();
    printListeHeals(listeW);
    ListeRessourcesCraft* listeRC = initRessourcesCraft();
    printListeHeals(listeRC);
    ListeArmor* listeA = initArmor();
    printListeArmor(listeA);
    map map;
    mapGridGenerator(&map);
    displayMap(&map);
    mapFreeGrid(&map);
    return 0;
}