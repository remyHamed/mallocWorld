#include "tools.h"

ListeTools* initTools()
{
    ListeTools* ListeTools = malloc(sizeof(*ListeTools));
    char const* const fileName = "items/tools.txt";
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
        Tools* tool = malloc(sizeof(*tool));
        while(token != NULL) {
            if(count == 0)
            {
                tool->name = malloc(sizeof(char) * strlen(token)+ 1);
                strcpy(tool->name, token);
                count += 1;
            }
            else 
            {
                tool->durability = malloc(sizeof(int));
                tool->durability = atoi(token);
                tool->next = ListeTools->first;
                ListeTools->first = tool;
                count = 0;
            }
            token = strtok (NULL, separator);
        }
    }
    fclose(file);
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