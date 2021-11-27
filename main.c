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
    // Heals** tabHeals = initHeals(); //marche
    // printHeals(tabHeals);

    // Weapons** tabWeapons = initWeapons();
    // printWeapons(tabWeapons);

    // Ressources** tabRessources = initRessources();
    // printRessources(tabRessources);

    Armors** tabArmors = initArmors();
    printArmors(tabArmors);

    // Tools** tabTools = initTools(); 
    // printTools(tabTools);

    // Crafts** tabCrats = initCrafts(); 
    // printCrafts(tabCrats);

    Bag* bag = initStartBag();
    char *** contentBag = bag->content;
    
    char** item = structToTabStrArmor(findOneArmor(tabArmors, 22));
    addItem(bag, item);
    printBag(contentBag);
    // free(bag->content[i][j]);
    // free(bag->content[i]);
    free(bag->content);

    return 0;
}