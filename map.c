#include "map.h"

/*
 *   param : no
 *   return : int between 7 and 11
*/
int twoPowerRandomPlusonGenerator() {
    srand(time(NULL));
    int min = 7;
    int max = 11;
    int powerOftwo = rand() % (max - min + 1) + min; 
    printf("twoPowerRandomPlusonGenerator() =  %d\n", powerOftwo); 
    return powerOftwo;
}
/*
 *   param :  no
 *   return : int between 2^7 + 1 and 2^11 + 1
*/
int genMapSize() {
    int powerOfTwo = twoPowerRandomPlusonGenerator();
    int result = pow(2,powerOfTwo);
    printf("genMapSize() = %d\n",result);
    return result + 1;
}

/*
 *   param : struct Map, int equal to 1,2,3
 *   return : map
*/
Map * setConersMap(Map* m, int zone) {
    srand(time(NULL));
        int min;
        int max;
        int s;
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
    s = m->size; 
    m->gird[0][0] =  rand() % (max - min + 1) + min;
    m->gird[s - 1][0] =  rand() % (max - min + 1) + min;
    m->gird[0][s - 1] =  rand() % (max - min + 1) + min;
    m->gird[s - 1][s - 1] =  rand() % (max - min + 1) + min;
    return m;
}
/*
 *   param : struct map
 *   return : nothing
*/
void displayMap(Map * m) {
    printf("displayMap\n"); 
    for(int i = 0; i < m->size; i++) {
        for (int j = 0; j < m->size; j++) {
            printf("%d", m->gird[i][j]);
        }
        printf("\n"); 
    }
}
/*
 *   param : integer zone
 *   return : a map
*/
Map *  mapGridGenerator(int zone) {
    int s;
    Map * m = malloc(sizeof(Map));
    m->size = malloc(sizeof(int));
    m->levelLImit = NULL; 
    m->size = genMapSize(); // gen a number whos (2^N) + 1
    s = m->size;
    printf("taill de la carte = %d", m->size);
    m->gird = malloc(sizeof(int*) * s);
    for(int i = 0; i < m->size; i++) {
       m->gird[i] = malloc(sizeof(int) * s); 
    }
    for(int i = 0; i < m->size; i++) {
        printf("i = %d\n", i);
        for (int j = 0; j < m->size; j++) {
            m->gird[i][j] = 0;
        }
    }
    m = setConersMap(m,zone);
    return m;
}
/*
 *   param : nothing 
 *   return : map
 * fonction a n'utiliser que pour les testes
*/
Map *  genMapForTest() {
    int s;
    Map * m = malloc(sizeof(Map));
    m->size = malloc(sizeof(int));
    m->levelLImit = NULL; 
    m->size = 100; // gen a number whos (2^N) + 1
    s = m->size;
    printf("taill de la carte = %d", m->size);
    m->gird = malloc(sizeof(int*) * s);
    for(int i = 0; i < m->size; i++) {
       m->gird[i] = malloc(sizeof(int) * s); 
    }
    for(int i = 0; i < m->size; i++) {
        printf("i = %d", i);
        for (int j = 0; j < m->size; j++) {
            m->gird[i][j] = 0;
        }
        printf("\n"); 
    }
    return m;
}

/*
 *   param : 
 *   return : 
*/
void mapFreeGrid(Map* wolrd) {
    printf("mapFreeGrid\n");   
    for(int i = 0; i <  wolrd->size; i++) {
            free(wolrd->gird[i]);
    } 
    free(wolrd->gird);
}

/*
 *   param : 
 *   return : 
*/

Map * magicDiamondSquare(Map* m) {
    int chunkSize = m->size - 1;
    int roughness = 2;
    int half ;
    while (chunkSize > 1) {
        half = chunkSize / 2;
        roughness/=2;
    }
    
    return m;
}


/*
void squareStep(int half, int chunk_square, Map* m, int randMax, int randMin) {
    int result = 0;
    for(int y = 0; y < m->size; y += chunk_square ) {
        printf("i = %d\n", y);
        for (int x = 0; x < m->size; x++) {
            result = m->gird[y][ x ] +
            m->gird[y][ x + chunk_square] +
            m->gird[y + chunk_square][ x ] +
            m->gird[y + chunk_square][ x + chunk_square];
            result /= 4;
            result += randMaxOrRandMin(randMin, randMax); // map->gird[y + half][ x + half] correspond au point central du carre
        }
    } 
}*/

int randMaxOrRandMin(int min, int max){
    srand(time(NULL));
    int res;
    res = rand() % (100 - 1 + 1) + 1; 
    if(res % 2 == 0) {
        return max;
    }
    return min;
}