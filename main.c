#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "craft.h"
#include "tools.h"
#include "weapons.h"
#include "ressources.h"
#include "heals.h"
#include "armor.h"

int main(int argc, char ** argv) 
{
    ListeCraft* listeC = initCraft(); // marche
    printListeCraft(listeC);

    // ListeTools* listeT = initTools(); // marche
    // printListeTools(listeT);

    // ListeHeals* listeH = initHeals(); // marche
    // printListeHeals(listeH);

    // ListeWeapons* listeW = initWeapons(); // marche
    // printListeWeapons(listeW);

    // ListeRessources* listeRC = initRessources(); // marche
    // printListeRessources(listeRC);

    // ListeArmor* listeA = initArmor(); // marche
    // printListeArmor(listeA);
    
    return 0;
}