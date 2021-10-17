#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;


typedef struct Craft Craft;
struct  Craft
{
    char* name;
    char* composant1;
    int nbComposant1;
    char* composant2;
    int nbComposant2;

    Craft* next;
};

typedef struct ListeCraft ListeCraft;
struct ListeCraft
{
    Craft *first;
};

ListeCraft* initCraft()
{
    ListeCraft* listeCraft = malloc(sizeof(*listeCraft));

    Craft* epeeBois = malloc(sizeof(*epeeBois));
    epeeBois->name = "Épée en bois";
    epeeBois->composant1 = "Sapin";
    epeeBois->nbComposant1 = 3;
    epeeBois->composant2 = "";
    epeeBois->nbComposant2 = 0;
    listeCraft->first = epeeBois;
    
    Craft* epeePierre = malloc(sizeof(*epeePierre));
    epeePierre->name = "Épée en pierre";
    epeePierre->composant1 = "Sapin";
    epeePierre->nbComposant1 = 2;
    epeePierre->composant2 = "Pierre";
    epeePierre->nbComposant2 = 3;

    Craft* epeeFer = malloc(sizeof(*epeeFer));
    epeeFer->name = "Épée en fer";
    epeeFer->composant1 = "Hêtre";
    epeeFer->nbComposant1 = 2;
    epeeFer->composant2 = "Fer";
    epeeFer->nbComposant2 = 4;

    Craft* epeeDiamant = malloc(sizeof(*epeeDiamant));
    epeeDiamant->name = "Épée en diamant";
    epeeDiamant->composant1 = "Chêne";
    epeeDiamant->nbComposant1 = 2;
    epeeDiamant->composant2 = "Diamant";
    epeeDiamant->nbComposant2 = 5;

    Craft* lanceEnPierre = malloc(sizeof(*lanceEnPierre));
    lanceEnPierre->name = "Lance en pierre";
    lanceEnPierre->composant1 = "Sapin";
    lanceEnPierre->nbComposant1 = 3;
    lanceEnPierre->composant2 = "Pierre";
    lanceEnPierre->nbComposant2 = 4;

    Craft* lanceFer = malloc(sizeof(*lanceFer));
    lanceFer->name = "Lance en fer";
    lanceFer->composant1 = "Hêtre";
    lanceFer->nbComposant1 = 3;
    lanceFer->composant2 = "Fer";
    lanceFer->nbComposant2 = 5;

    Craft* lanceDiamant = malloc(sizeof(*lanceDiamant));
    lanceDiamant->name = "Lance en diamant";
    lanceDiamant->composant1 = "Chêne";
    lanceDiamant->nbComposant1 = 3;
    lanceDiamant->composant2 = "Diamant";
    lanceDiamant->nbComposant2 = 6;

    Craft* marteauPierre = malloc(sizeof(*marteauPierre));
    marteauPierre->name = "Marteau en pierre";
    marteauPierre->composant1 = "Sapin";
    marteauPierre->nbComposant1 = 2;
    marteauPierre->composant2 = "Pierre";
    marteauPierre->nbComposant2 = 6;

    Craft* marteauFer = malloc(sizeof(*marteauFer));
    marteauFer->name = "Marteau en fer";
    marteauFer->composant1 = "Hêtre";
    marteauFer->nbComposant1 = 2;
    marteauFer->composant2 = "Fer";
    marteauFer->nbComposant2 = 7;
    
    Craft* marteauDiamant = malloc(sizeof(*marteauDiamant));
    marteauDiamant->name = "Marteau en diamant";
    marteauDiamant->composant1 = "Chêne";
    marteauDiamant->nbComposant1 = 2;
    marteauDiamant->composant2 = "Diamant";
    marteauDiamant->nbComposant2 = 8;

    Craft* plastronPierre = malloc(sizeof(*plastronPierre));
    plastronPierre->name = "Plastron en pierre";
    plastronPierre->composant1 = "Pierre";
    plastronPierre->nbComposant1 = 10;
    plastronPierre->composant2 = "";
    plastronPierre->nbComposant2 = 0;

    Craft* plastronFer = malloc(sizeof(*plastronFer));
    plastronFer->name = "Plastron en fer";
    plastronFer->composant1 = "Fer";
    plastronFer->nbComposant1 = 12;
    plastronFer->composant2 = "";
    plastronFer->nbComposant2 = 0;

    Craft* plastronDiamant = malloc(sizeof(*plastronDiamant));
    plastronDiamant->name = "Plastron en diamant";
    plastronDiamant->composant1 = "Diamant";
    plastronDiamant->nbComposant1 = 16;
    plastronDiamant->composant2 = "";
    plastronDiamant->nbComposant2 = 0;

    Craft* piocheBois = malloc(sizeof(*piocheBois));
    piocheBois->name = "Pioche en bois";
    piocheBois->composant1 = "Sapin";
    piocheBois->nbComposant1 = 3;
    piocheBois->composant2 = "";
    piocheBois->nbComposant2 = 0;

    Craft* piochePierre = malloc(sizeof(*piochePierre));
    piochePierre->name = "Pioche en pierre";
    piochePierre->composant1 = "Sapin";
    piochePierre->nbComposant1 = 2;
    piochePierre->composant2 = "Pierre";
    piochePierre->nbComposant2 = 3;

    Craft* piocheFer = malloc(sizeof(*piocheFer));
    piocheFer->name = "Pioche en fer";
    piocheFer->composant1 = "Hêtre";
    piocheFer->nbComposant1 = 2;
    piocheFer->composant2 = "Fer";
    piocheFer->nbComposant2 = 4;

    Craft* hacheBois = malloc(sizeof(*hacheBois));
    hacheBois->name = "Hache en bois";
    hacheBois->composant1 = "Sapin";
    hacheBois->nbComposant1 = 3;
    hacheBois->composant2 = "";
    hacheBois->nbComposant2 = 0;

    Craft* hachePierre = malloc(sizeof(*hachePierre));
    hachePierre->name = "Hache en pierre";
    hachePierre->composant1 = "Sapin";
    hachePierre->nbComposant1 = 2;
    hachePierre->composant2 = "Pierre";
    hachePierre->nbComposant2 = 3;

    Craft* hacheFer = malloc(sizeof(*hacheFer));
    hacheFer->name = "Hache en fer";
    hacheFer->composant1 = "Hêtre";
    hacheFer->nbComposant1 = 2;
    hacheFer->composant2 = "Fer";
    hacheFer->nbComposant2 = 4;

    Craft* serpeBois = malloc(sizeof(*serpeBois));
    serpeBois->name = "Serpe en bois";
    serpeBois->composant1 = "Sapin";
    serpeBois->nbComposant1 = 3;
    serpeBois->composant2 = "";
    serpeBois->nbComposant2 = 0;

    Craft* serpePierre = malloc(sizeof(*serpePierre));
    serpePierre->name = "Serpe en pierre";
    serpePierre->composant1 = "Sapin";
    serpePierre->nbComposant1 = 2;
    serpePierre->composant2 = "Pierre";
    serpePierre->nbComposant2 = 3;

    Craft* serpeFer = malloc(sizeof(*serpeFer));
    serpeFer->name = "Serpe en fer";
    serpeFer->composant1 = "Hêtre";
    serpeFer->nbComposant1 = 2;
    serpeFer->composant2 = "Fer";
    serpeFer->nbComposant2 = 4;

    Craft* potion1 = malloc(sizeof(*potion1));
    potion1->name = "Potion de vie I";
    potion1->composant1 = "Herbe";
    potion1->nbComposant1 = 2;
    potion1->composant2 = "";
    potion1->nbComposant2 = 0;

    Craft* potion2 = malloc(sizeof(*potion2));
    potion2->name = "Potion de vie II";
    potion2->composant1 = "Lavande";
    potion2->nbComposant1 = 2;
    potion2->composant2 = "";
    potion2->nbComposant2 = 0;

    Craft* potion3 = malloc(sizeof(*potion3));
    potion3->name = "Potion de vie III";
    potion3->composant1 = "Chanvre";
    potion3->nbComposant1 = 2;
    potion3->composant2 = "";
    potion3->nbComposant2 = 0;
    
    epeeBois->next = epeePierre;
    epeePierre->next = epeeFer;
    epeeFer->next = epeeDiamant;
    epeeDiamant->next = lanceEnPierre;
    lanceEnPierre->next = lanceFer;
    lanceFer->next = lanceDiamant;
    lanceDiamant->next = marteauPierre;
    marteauPierre->next = marteauFer;
    marteauFer->next = marteauDiamant;
    marteauDiamant->next = plastronPierre;
    plastronPierre->next = plastronFer;
    plastronFer->next = plastronDiamant;
    plastronDiamant->next = piocheBois;
    piocheBois->next = piochePierre;
    piochePierre->next = piocheFer;
    piocheFer->next = hacheBois;
    hacheBois->next = hachePierre;
    hachePierre->next = hacheFer;
    hacheFer->next = serpeBois;
    serpeBois->next = serpePierre;
    serpePierre->next = serpeFer;
    serpeFer->next = potion1;
    potion1->next = potion2;
    potion2->next = potion3;
    potion3->next = NULL;

    return listeCraft;
}

void printListeCraft(ListeCraft* listeCraft)
{
    if (listeCraft == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Craft* actual = listeCraft->first;

    while (actual != NULL)
    {
        printf("Nom : %s\n", actual->name);
        printf("Composant 1 : %s\n", actual->composant1);
        printf("Qte : %d\n", actual->nbComposant1);
        printf("Composant 2 : %s\n", actual->composant2);
        printf("Qte : %d\n\n", actual->nbComposant2);
        actual = actual->next;
    }
    printf("NULL\n");
}

int main(int argc, const char* argv[])
{

    ListeCraft* listec = initCraft();
    printListeCraft(listec);
    return 0;
}
