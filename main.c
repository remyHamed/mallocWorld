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
    ListeCraft* listeC = initCraft();
    printListeCraft(listeC);

    ListeHeals* listeH = initHeals();
    printListeHeals(listeH);

    ListeTools* listeT = initTools();
    printListeTools(listeT);

    ListeWeapons* listeW = initWeapons();
    printListeWeapons(listeW);

    ListeRessourcesCraft* listeRC = initRessourcesCraft();
    printListeRessourcesCraft(listeRC);

    ListeArmor* listeA = initArmor();
    printListeArmor(listeA);
    
    return 0;
}