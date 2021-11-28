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
#include "headers/fFileReading.h"


int main(int argc, char ** argv) 
{
    Heals** tabHeals = initHeals();
    Weapons** tabWeapons = initWeapons();
    Ressources** tabRessources = initRessources();
    Armors** tabArmors = initArmors();
    Tools** tabTools = initTools();
    Crafts** tabCrats = initCrafts();

    Bag* bag = initStartBag();
    char *** contentBag = bag->content;
    
    char** item = structToTabHeal(findOneHeal(tabHeals, 26));
    addItem(bag, item);
    char** item2 = structToTabWeapon(findOneWeapon(tabWeapons, 26));
    printBag(contentBag);
    return 0;
}