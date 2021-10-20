#include "map.h"

int twoPowerRandomPlusonGenerator() {
    srand(time(NULL));
    int min = 7;
    int max = 11;
    int mapSize = rand() % (max - min + 1) + min; 
    return mapSize;
}

map * setConersMap(map * map, int zone) {
    srand(time(NULL));
        int min;
        int max;
    if (zone == 1) {
        min = 3;
        max = 100;
    }
    if (zone == 2) {
        min = 6;
        max = 100; 
    }
    if (zone == 3) {
        min = 6;
        max = 100;  
    }
    map->gird[0][0] =  rand() % (max - min + 1) + min;
    map->gird[map->size - 1][0] =  rand() % (max - min + 1) + min;
    map->gird[0][map->size - 1] =  rand() % (max - min + 1) + min;
    map->gird[map->size - 1][map->size - 1] =  rand() % (max - min + 1) + min;
    return map;
}

void displayMap(map * map) {
    printf("displayMap\n"); 
    for(int i = 0; i < map->size; i++) {
        for (int j = 0; j < map->size; j++) {
            printf("%d", map->gird[i][j]);
        }
        printf("\n"); 
    }
}

map *  mapGridGenerator(map * map, int zone) {
    printf("mapGridGenerator\n");  
    map->size = twoPowerRandomPlusonGenerator(); // gen a number whos (2^N) + 1
    map->gird = malloc(sizeof(int*) * map->size);
    for(int i = 0; i <     map->size; i++) {
       map->gird[i] = malloc(sizeof(int) * map->size); 
    }
    for(int i = 0; i < map->size; i++) {
        printf("i = %d\n", i);
        for (int j = 0; j < map->size; j++) {
            map->gird[i][j] = 0;
        }
    }
    map = setConersMap(map,zone);
    return map;
}

void mapFreeGrid(map* map) {
    printf("mapFreeGrid\n");   
    for(int i = 0; i <  map->size; i++) {
            free(map->gird[i]);
    } 
    free(map->gird);
}

map * magicDiamondSquare(map* map) {
    int chunkSize = map->size - 1;
    int roughness = 2;
    int half ;
    while (chunkSize > 1) {
        half = chunkSize / 2;
        roughness/=2;
    }
    
    return map;
}

void squareStep(int half, int chunk_square, map * map, int randMax, int randMin) {
    int result = 0;
   for(int y = 0; y < map->size; y += chunk_square ) {
        printf("i = %d\n", i);
        for (int x = 0; j < map->size; j++) {
            result = map->gird[y][ x ] +
            map->gird[y][ x + chunk_square] +
            map->gird[y + chunk_square][ x ] +
            map->gird[y + chunk_square][ x + chunk_square];
            result /= 4;
            result += randMaxOrRandMin(randMin, randMax);
            ; // map->gird[y + half][ x + half] correspond au point central du carre
        }
    } 
}

int randMaxOrRandMin(int min, int max){
    srand(time(NULL));
    int res;
    res = rand() % (100 - 1 + 1) + 1; 
    if(res % 2 == 0) {
        return max;
    }
    return min;
}