#include "intArrFun.h"

/*
    1
    int ** arr2d(int size)
    Param: integer for array size
    return: integer array

*/

int ** arr2d(int size) {
    int ** arr = malloc(sizeof(int *) * size);
    for (size_t i = 0; i < size; i++) {
        arr[i] = malloc(sizeof(int) * size);
    }
    return arr;
}

/*
    2
    void Arr2dFree(int ** arr, int size)
    Param: integer ** array
    Param: integer size of the array
    return: nothing

*/

void Arr2dFree(int ** arr, int size) {
    for (size_t i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);
    return arr;
}

/*
    3
    void Arr2dDipslay(int ** arr, int size)
    Param: integer ** array
    Param: integer size of the array
    return: nothing

*/

void Arr2dDipslay(int ** arr, int size) {
    for (size_t i = 0; i < size; i++) {
        for(size_t j = 0; j < size; j++) {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}


/*

    void Arr2dSet0(int ** arr, int size)
    Param: integer ** array
    Param: integer size of the array
    return: nothing

*/

void Arr2dSet0(int ** arr, int size) {
    for (size_t i = 0; i < size; i++) {
        for(size_t j = 0; j < size; j++) {
            arr[i][j] = 0;
        }
        printf("\n");
    }
}