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
#include "headers/bag.h"


int main(int argc, char ** argv) 
{
    // Heals** tabHeals = initHeals();
    // printHeals(tabHeals);

    // Weapons** tabWeapons = initWeapons();
    // printWeapons(tabWeapons);

    // Ressources** tabRessources = initRessources();
    // printRessources(tabRessources);

    // Armors** tabArmors = initArmors();
    // printArmors(tabArmors);

    // Tools** tabTools = initTools(); 
    // printTools(tabTools);

    // Crafts** tabCrats = initCrafts(); 
    // printCrafts(tabCrats);

    char*** bag =  createStartBag();
    printBag(bag);

    return 0;
}