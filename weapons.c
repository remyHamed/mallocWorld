#include "weapons.h"

ListeWeapons* initWeapons()
{
    ListeWeapons* ListeWeapons = malloc(sizeof(*ListeWeapons));
    char const* const fileName = "items/weapons.txt";
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
        Weapons* weapon = malloc(sizeof(*weapon));
        while(token != NULL) {
            if(count == 0)
            {
                weapon->name = malloc(sizeof(char) * strlen(token)+ 1);
                strcpy(weapon->name, token);
                count += 1;
            }
            else if(count == 1)
            {
                weapon->damage = malloc(sizeof(int));
                weapon->damage = atoi(token);
                count += 1;
            }
            else
            {
                weapon->durability = malloc(sizeof(int));
                weapon->durability = atoi(token);
                weapon->next = ListeWeapons->first;
                ListeWeapons->first = weapon;
                count = 0;
            }
            token = strtok (NULL, separator);
        }
    }
    fclose(file);
    return ListeWeapons;
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