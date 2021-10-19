#include "weapons.h"

ListeWeapons* initWeapons()
{
    ListeWeapons* listeWeapons = malloc(sizeof(*listeWeapons));

    Weapons* epeeBois = malloc(sizeof(*epeeBois));
    epeeBois->name = "Épée en bois";
    epeeBois->damage = 1;
    epeeBois->durability = 10;
    listeWeapons->first = epeeBois;
    
    Weapons* epeePierre = malloc(sizeof(*epeePierre));
    epeePierre->name = "Épée en pierre";
    epeePierre->damage = 2;
    epeePierre->durability = 10;

    Weapons* epeeFer = malloc(sizeof(*epeeFer));
    epeeFer->name = "Épée en fer";
    epeeFer->damage = 5;
    epeeFer->durability = 10;

    Weapons* epeeDiamant = malloc(sizeof(*epeeDiamant));
    epeeDiamant->name = "Épée en diamant";
    epeeDiamant->damage = 10;
    epeeDiamant->durability = 10;

    Weapons* lanceEnPierre = malloc(sizeof(*lanceEnPierre));
    lanceEnPierre->name = "Lance en pierre";
    lanceEnPierre->damage = 3;
    lanceEnPierre->durability = 8;

    Weapons* lanceFer = malloc(sizeof(*lanceFer));
    lanceFer->name = "Lance en fer";
    lanceFer->damage = 7;
    lanceFer->durability = 8;

    Weapons* lanceDiamant = malloc(sizeof(*lanceDiamant));
    lanceDiamant->name = "Lance en diamant";
    lanceDiamant->damage = 15;
    lanceDiamant->durability = 8;

    Weapons* marteauPierre = malloc(sizeof(*marteauPierre));
    marteauPierre->name = "Marteau en pierre";
    marteauPierre->damage = 4;
    marteauPierre->durability = 5;

    Weapons* marteauFer = malloc(sizeof(*marteauFer));
    marteauFer->name = "Marteau en fer";
    marteauFer->damage = 10;
    marteauFer->durability = 5;

    Weapons* marteauDiamant = malloc(sizeof(*marteauDiamant));
    marteauDiamant->name = "Marteau en pierre";
    marteauDiamant->damage = 20;
    marteauDiamant->durability = 5;

    epeeBois->next = epeePierre;
    epeePierre->next = epeeFer;
    epeeFer->next = epeeDiamant;
    epeeDiamant->next = lanceEnPierre;
    lanceEnPierre->next = lanceFer;
    lanceFer->next = lanceDiamant;
    lanceDiamant->next = marteauPierre;
    marteauPierre->next = marteauFer;
    marteauFer->next = marteauDiamant;

    return listeWeapons;
}

void printListeWeapons(ListeWeapons* listeWeapons)
{
    if (listeWeapons == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Weapons* actual = listeWeapons->first;

    while (actual != NULL)
    {
        printf("Nom : %s\n", actual->name);
        printf("Damage : %d\n", actual->damage);
        printf("Durability: %d\n\n", actual->durability);
        actual = actual->next;
    }
    printf("NULL\n");
}