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

    // Heals** tab_H = initHeals(); // marche
    // printHeals(tab_H);

    Weapons** tab_W = initWeapons();
    printWeapons(tab_W);

    // Ressources** tab_RC = initRessources(); // marche
    // printRessources(tab_RC);

    // ListeArmor* listeA = initArmor();
    // printListeArmor(listeA);

    return 0;
}