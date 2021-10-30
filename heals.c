#include "headers/heals.h"

ListeHeals* initHeals()
{
    ListeHeals* ListeHeals = malloc(sizeof(*ListeHeals));
    char const* const fileName = "items/heals.txt";
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
        Heals* heal = malloc(sizeof(*heal));
        while(token != NULL) {
            if(count == 0)
            {
                heal->name = malloc(sizeof(char) * strlen(token)+ 1);
                strcpy(heal->name, token);
                count += 1;
            }
            else 
            {
                heal->heal = malloc(sizeof(int));
                heal->heal = atoi(token);
                heal->next = ListeHeals->first;
                ListeHeals->first = heal;
                count = 0;
            }
            token = strtok (NULL, separator);
        }
    }
    fclose(file);
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
}