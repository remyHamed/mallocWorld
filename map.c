#include "map.h"

/*   function Diamond square
 *   param : no
 *   return : int between 7 and 11
 * 
 *  cette fonction retourne 2^n + 1 pour la génétationde la carte
 *  la cart doit être dans ces dimension pour l'algorithme
*/
int twoPowerRandomPlusonGenerator() {
    srand(time(NULL));
    int min = 7;
    int max = 11;
    int powerOftwo = rand() % (max - min + 1) + min; 
    printf("twoPowerRandomPlusonGenerator() =  %d\n", powerOftwo); 
    return powerOftwo;
}
/*  function Diamond square
 *   param :  no
 *   return : int between 2^7 + 1 and 2^11 + 1
 * 
 *  la fonction fait le calcul de la taille
*/
int genMapSize() {
    int powerOfTwo = twoPowerRandomPlusonGenerator();
    int result = pow(2,powerOfTwo);
    return result + 1;
}

/*   function Diamond square
 *   param : struct Map, int equal to 1,2,3
 *   return : map
 *   
 *   on set les 5_4 coinbs de la carte a un chiffre pour débuter le calcult des moyennes
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
    param: int min, int max
    return : int

    la fonction retourn un chiffre
    on mes les limites dans la fourchetes des 
    valeurs disponible
    3 à 5 pour le permier monde etc.
*/
int randMaxOrRandMin(int min, int max){
    srand(time(NULL));
    int res;
    res = rand() % (100 - 1 + 1) + 1; 
    if(res % 2 == 0) {
        return max;
    }
    return min;
}

/* function Diamond square
 *   param : 
 *   return : 
*/

/*Map * magicDiamondSquare(Map* m) {
    int chunkSize = m->size - 1;            ANCHOR cette fonction n'est pas fini
    int roughness = 2;
    int half ;
    while (chunkSize > 1) {
        half = chunkSize / 2;
        roughness/=2;
    }
    
    return m;
}*/


/*
void squareStep(int half, int chunk_square, Map* m, int randMax, int randMin) ANCHOR cette fonction n'est pas fini   int result = 0;
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

