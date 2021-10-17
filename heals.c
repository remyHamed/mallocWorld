#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Heals Heals;
struct  Heals
{
    char* name;
    int heal;

    Heals* next;
};

typedef struct ListeHeals ListeHeals;
struct ListeHeals
{
    ListeHeals* first;
};

ListeHeals* initHeals()
{
    ListeHeals* ListeHeals = malloc(sizeof(*ListeHeals));

    Heals* potion1 = malloc(sizeof(*potion1));
    potion1->name = "Potion de vie I";
    potion1->heal = 30;
    ListeHeals->first = potion1;

    Heals* potion2 = malloc(sizeof(*potion2));
    potion2->name = "Potion de vie II";
    potion2->heal = 80;

    Heals* potion3 = malloc(sizeof(*potion3));
    potion3->name = "Potion de vie III";
    potion3->heal = 200;

    potion1->next = potion2;
    potion2->next = potion3;
    potion3->next = NULL;

    return ListeHeals;
}

void printListeHeals(ListeHeals* ListeHeals)
{
    if (ListeHeals == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Heals* actual = ListeHeals->first;

    while (actual != NULL)
    {
        printf("Nom : %s\n", actual->name);
        printf("heal : %d\n\n", actual->heal);
        actual = actual->next;
    }
    printf("NULL\n");
}

int main(int argc, const char* argv[])
{

    ListeHeals* listeT = initHeals();
    printListeHeals(listeT);
    return 0;
}