#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "headers/craft.h"
#include "headers/tools.h"
#include "headers/weapons.h"
#include "headers/ressources.h"
#include "headers/heals.h"
#include "headers/armor.h"

int main(int argc, char ** argv) 
{

    Heals** tab_H = initHeals(); // marche
    printHeals(tab_H);

    Weapons** tab_W = initWeapons(); // marche
    printWeapons(tab_W);

    Ressources** tab_RC = initRessources(); // marche
    printRessources(tab_RC);

    Armors** tab_A = initArmors(); // marche
    printArmors(tab_A);

    Tools** tab_T = initTools(); 
    printTools(tab_T);

    Crafts** tab_C = initCrafts(); 
    printCrafts(tab_C);

    return 0;
}