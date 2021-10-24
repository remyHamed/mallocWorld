#include "ressources.h"

ListeRessourcesCraft* initRessourcesCraft()
{
    ListeRessourcesCraft* listeRessourcesCraft = malloc(sizeof(*listeRessourcesCraft));

    RessourcesCraft* sapin = malloc(sizeof(*sapin));
    sapin->name = "Sapin";
    sapin->holdLimit = 20;
    listeRessourcesCraft->first = sapin;

    RessourcesCraft* hetre = malloc(sizeof(*hetre));
    hetre->name = "Hêtre";
    hetre->holdLimit = 20;

    RessourcesCraft* chene = malloc(sizeof(*chene));
    chene->name = "Chêne";
    chene->holdLimit = 20;

    RessourcesCraft* pierre = malloc(sizeof(*pierre));
    pierre->name = "Pierre";
    pierre->holdLimit = 20;
    
    RessourcesCraft* fer = malloc(sizeof(*fer));
    fer->name = "Fer";
    fer->holdLimit = 20;

    RessourcesCraft* diamant = malloc(sizeof(*diamant));
    diamant->name = "Diamant";
    diamant->holdLimit = 20;

    RessourcesCraft* herbe = malloc(sizeof(*herbe));
    herbe->name = "Herbe";
    herbe->holdLimit = 20;

    RessourcesCraft* lavande = malloc(sizeof(*lavande));
    lavande->name = "Lavande";
    lavande->holdLimit = 20;

    RessourcesCraft* chanvre = malloc(sizeof(*chanvre));
    chanvre->name = "Chanvre";
    chanvre->holdLimit = 20;

    sapin->next = hetre;
    hetre->next = chene;
    chene->next = pierre;
    pierre->next = fer;
    fer->next = diamant;
    diamant->next = herbe;
    herbe->next = lavande;
    lavande->next = chanvre;
    chanvre->next = NULL;

    return listeRessourcesCraft;
}

void printListeRessourcesCraft(ListeRessourcesCraft* ListeRessourcesCraft)
{
    if (ListeRessourcesCraft == NULL)
    {
        exit(EXIT_FAILURE);
    }

    RessourcesCraft* actual = ListeRessourcesCraft->first;

    while (actual != NULL)
    {
        printf("Nom : %s\n", actual->name);
        printf("Limit : %d\n\n", actual->holdLimit);
        actual = actual->next;
    }
    printf("NULL\n");
}