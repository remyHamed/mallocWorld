#include "map.h"

void displayMap(map * map) {
    printf("displayMap\n"); 
    for(int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            printf("%d", map->gird[i][j]);
        }
        printf("\n"); 
    }
}

void mapGridGenerator(map * map) {
    printf("mapGridGenerator\n");  
    srand(time(NULL));
    int min = 4;
    int max = 90;
    int wdth = rand() % (max - min + 1) + min; // genenration de la taill de la map
    int hght = rand() % (max - min + 1) + min;
    map->height = hght;
    map->width = wdth;
    map->gird = malloc(sizeof(int*) * hght);
    for(int i = 0; i < hght; i++) {
       map->gird[i] = malloc(sizeof(int) * wdth); 
    }
    for(int i = 0; i < hght; i++) {
        printf("i = %d\n", i);
        for (int j = 0; j < wdth; j++) {
            map->gird[i][j] = 0;
        }
    }
    
}

void mapFreeGrid(map* map) {
    printf("mapFreeGrid\n");   
    for(int i = 0; i < map->height; i++) {
            free(map->gird[i]);
    } 
    free(map->gird);
}