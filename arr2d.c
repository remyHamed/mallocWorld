#include "arr2d.h"

/*
    PARAM:
    integer it give the array size

    RETURN:
    int ** array
*/
int ** genArr2d(int size) {
    int ** arr = malloc(sizeof(int**) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = malloc(sizeof(int*)); 
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = malloc(sizeof(int)); 
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = 0; 
        }
    }
    return arr;
}
/*
    PARAM:
    int** it give the array address
    int size give sive of array
    
    RETURN:
    nothing
*/
void setArr2d(int**a, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            a[i][j] = 0 ;
        }
    }
}
/*
    PARAM:
    int* it give the array address
    int size give sive of array
    
    RETURN:
    nothing
*/
void diplsayArr2d(int** a, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }
}