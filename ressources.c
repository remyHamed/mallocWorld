#include "headers/ressources.h"

ListeRessources* initRessources()
{
    ListeRessources* ListeRessources = malloc(sizeof(*ListeRessources));
    char const* const fileName = "items/ressources.txt";
    FILE* file = fopen(fileName, "r"); /* should check the result */
    if (file == NULL)
    {
        printf("Fichier non ouvert");
    }
    char line[256];
    const char * separator = "|";
    int count = 0;

    while (fgets(line, sizeof(line), file)) {
        char* token = strtok (line, separator);
        Ressources* ressource = malloc(sizeof(*ressource));
        while(token != NULL) {
            if(count == 0)
            {
                ressource->name = malloc(sizeof(char) * strlen(token)+ 1);
                strcpy(ressource->name, token);
                count += 1;
            }
            else 
            {
                ressource->holdLimit = malloc(sizeof(int));
                ressource->holdLimit = atoi(token);
                ressource->next = ListeRessources->first;
                ListeRessources->first = ressource;
                count = 0;
            }
            token = strtok (NULL, separator);
        }
    }
    fclose(file);
    return ListeRessources;
}

void printListeRessources(ListeRessources* ListeRessources)
{
    if (ListeRessources == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Ressources* actual = ListeRessources->first;

    while (actual != NULL)
    {
        printf("Nom : %s\n", actual->name);
        printf("Limit : %d\n\n", actual->holdLimit);
        actual = actual->next;
    }
    printf("NULL\n");
}