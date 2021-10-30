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
    // ListeCraft* listeC = initCraft(); 
    // printListeCraft(listeC);

    ListeTools* listeT = initTools();
    printListeTools(listeT);

    // ListeHeals* listeH = initHeals();
    // printListeHeals(listeH);

    // ListeWeapons* listeW = initWeapons();
    // printListeWeapons(listeW);

    // ListeRessources* listeRC = initRessources(); 
    // printListeRessources(listeRC);

    // ListeArmor* listeA = initArmor();
    // printListeArmor(listeA);
    
    return 0;
}