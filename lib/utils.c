#include<stdlib.h>
#include<stdio.h>
#include<utils.h>

// LIB functions

/* print char array */
void printCharArray(char* array, unsigned int size) {
    unsigned int index = 0;
    if(!array)
        return;

    for(index=0; index<size; index++) {
        printf("%u ", array[index]);
    }
    printf("\n");
}

/* print int array */
void printIntArray(int* array, unsigned int size) {
    unsigned int index = 0;
    if(!array)
        return;

    for(index=0; index<size; index++) {
        printf("%d ", array[index]);
    }
    printf("\n");
}

/* print float array */
void printFloatArray(float* array, unsigned int size) {
    unsigned int index = 0;
    if(!array)
        return;

    for(index=0; index<size; index++) {
        printf("%f ", array[index]);
    }
    printf("\n");
}

