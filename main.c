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

int main(int argc, char ** argv) {
    Heals** tabHeals = initHeals();
    Weapons** tabWeapons = initWeapons();
    Ressources** tabRessources = initRessources();
    Armors** tabArmors = initArmors();
    Tools** tabTools = initTools();
    Crafts** tabCrats = initCrafts();
    Bag* bag = initStartBag();

    Weapons* arme1 = findOneWeapon(tabWeapons, 30);

    char** item3 = structToTabWeapon(arme1);
    addItem(bag, item3);
    
    Heals* soin1 = findOneHeal(tabHeals, 26);

    char** item = structToTabHeal(soin1);
    addItem(bag, item);
    // printf("1");
    // char** item2 = structToTabHeal(findOneHeal(tabHeals, 26));
    // addItem(bag, item2);
    // printf("2");
   
    
    // printf("3");
    printBag(bag);
    return 0;
}