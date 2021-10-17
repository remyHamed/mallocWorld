#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;

typedef struct Tools Tools;
struct  Tools
{
    char* name;
    int durability;

    Tools* next;
};

typedef struct ListeTools ListeTools;
struct ListeTools
{
    ListeTools* first;
};

ListeTools* initTools()
{
    ListeTools* ListeTools = malloc(sizeof(*ListeTools));

    Tools* piocheBois = malloc(sizeof(*piocheBois));
    piocheBois->name = "Pioche en bois";
    piocheBois->durability = 10;
    ListeTools->first = piocheBois;

    Tools* piochePierre = malloc(sizeof(*piochePierre));
    piochePierre->name = "Pioche en pierre";
    piochePierre->durability = 10;

    Tools* piocheFer = malloc(sizeof(*piocheFer));
    piocheFer->name = "Pioche en fer";
    piocheFer->durability = 10;

    Tools* serpeBois = malloc(sizeof(*serpeBois));
    serpeBois->name = "Serpe en bois";
    serpeBois->durability = 10;

    Tools* serpePierre = malloc(sizeof(*serpePierre));
    serpePierre->name = "Serpe en pierre";
    serpePierre->durability = 10;

    Tools* serpeFer = malloc(sizeof(*serpeFer));
    serpeFer->name = "Serpe en fer";
    serpeFer->durability = 10;

    Tools* hacheBois = malloc(sizeof(*hacheBois));
    hacheBois->name = "Hache en bois";
    hacheBois->durability = 10;

    Tools* hachePierre = malloc(sizeof(*hachePierre));
    hachePierre->name = "Hache en pierre";
    hachePierre->durability = 10;

    Tools* hacheFer = malloc(sizeof(*hacheFer));
    hacheFer->name = "Hache en fer";
    hacheFer->durability = 10;

    piocheBois->next = piochePierre;
    piochePierre->next = piocheFer;
    piocheFer->next = hacheBois;
    hacheBois->next = hachePierre;
    hachePierre->next = hacheFer;
    hacheFer->next = serpeBois;
    serpeBois->next = serpePierre;
    serpePierre->next = serpeFer;
    serpeFer->next = NULL;

    return ListeTools;
}

void printListeTools(ListeTools* ListeTools)
{
    if (ListeTools == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Tools* actual = ListeTools->first;

    while (actual != NULL)
    {
        printf("Nom : %s\n", actual->name);
        printf("Durability : %d\n\n", actual->durability);
        actual = actual->next;
    }
    printf("NULL\n");
}

int main(int argc, const char* argv[])
{

    ListeTools* listeT = initTools();
    printListeTools(listeT);
    return 0;
}