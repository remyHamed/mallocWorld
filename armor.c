#include "armor.h"

ListeArmor* initArmor()
{
    ListeArmor* ListeArmor = malloc(sizeof(*ListeArmor));

    Armor* plastronPierre = malloc(sizeof(*plastronPierre));
    plastronPierre->name = "Plastron en pierre";
    plastronPierre->resDamage = 10;
    ListeArmor->first = plastronPierre;

    Armor* plastronFer = malloc(sizeof(*plastronFer));
    plastronFer->name = "Plastron en fer";
    plastronFer->resDamage = 20;

    Armor* plastronDiamant = malloc(sizeof(*plastronDiamant));
    plastronDiamant->name = "Plastron en diamant";
    plastronDiamant->resDamage = 40;

    plastronPierre->next = plastronFer;
    plastronFer->next = plastronDiamant;
    plastronDiamant->next = NULL;

    return ListeArmor;
}

void printListeArmor(ListeArmor* ListeArmor)
{
    if (ListeArmor == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Armor* actual = ListeArmor->first;

    while (actual != NULL)
    {
        printf("Nom : %s\n", actual->name);
        printf("Pourcentge de resistance au dommages : %d\n\n", actual->resDamage);
        actual = actual->next;
    }
    printf("NULL\n");
}