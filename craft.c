#include "craft.h"

ListeCraft* initCraft()
{
    ListeCraft* ListeCraft = malloc(sizeof(*ListeCraft));
    char const* const fileName = "items/craft.txt";
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
        Craft* craft = malloc(sizeof(*craft));
        while(token != NULL) {
            switch (count)
            {
                case 0:
                    craft->name = malloc(sizeof(char) * strlen(token)+ 1);
                    strcpy(craft->name, token);
                    count += 1;
                    break;
            
                case 1:
                    craft->nbComposant1 = malloc(sizeof(int));
                    craft->nbComposant1 = atoi(token);
                    count += 1;
                    break;

                case 2:
                    craft->composant1 = malloc(sizeof(char) * strlen(token)+ 1);
                    strcpy(craft->composant1, token);
                    count += 1;
                    break;
                
                case 3:
                    craft->nbComposant2 = malloc(sizeof(int));
                    craft->nbComposant2 = atoi(token);
                    count += 1;
                    break;
                
                case 4:
                    craft->composant2 = malloc(sizeof(char) * strlen(token)+ 1);
                    strcpy(craft->composant2, token);
                    craft->next = ListeCraft->first;
                    ListeCraft->first = craft;
                    count = 0;
                    break;
            }
            token = strtok (NULL, separator);
        }
    }
    fclose(file);
    return ListeCraft;
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
        printf("Qte1 : %d\n", actual->nbComposant1);
        printf("Composant 2 : %s", actual->composant2);
        printf("Qte2 : %d\n\n", actual->nbComposant2);
        actual = actual->next;
    }
    printf("NULL\n");
}