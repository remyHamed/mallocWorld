#include "armor.h"

ListeArmor* initArmor()
{
    ListeArmor* ListeArmor = malloc(sizeof(*ListeArmor));
    char const* const fileName = "items/armor.txt";
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
        Armor* armor = malloc(sizeof(*armor));
        while(token != NULL) {
            if(count == 0){
                armor->name = malloc(sizeof(char) * strlen(token)+ 1);
                strcpy(armor->name, token);
                count += 1;
            }
            else {
                armor->resDamage = malloc(sizeof(int));
                armor->resDamage = atoi(token);
                armor->next = ListeArmor->first;
                ListeArmor->first = armor;
                count = 0;
            }
            token = strtok (NULL, separator);
        }
    }
    fclose(file);
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
        printf("Résistance au dommages : %d\n\n", actual->resDamage);
        actual = actual->next;
    }
    printf("NULL\n");
}