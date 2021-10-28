#include "arr2d.h"

int ** genArr2d(int size) {
    int ** a = malloc(sizeof(int*));
    for (int i = 0; i < size; i++) {
        for (size_t i = 0; i < count; i++)
        {
            a[i] = malloc(sizeof(int) * size);
        }
    }
    
    return a;
}

void setArr2d(int* a, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            a[i][j] = 0 ;
        }
    }
}

void diplsayArr2d(int* a, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
}