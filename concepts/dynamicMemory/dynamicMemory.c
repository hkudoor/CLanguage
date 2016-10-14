#include<stdlib.h>
#include<stdio.h>
#include<utils.h>

// defines
#define NUM_BYTES 100
#define NUM_INTS  25

// utility functions


// main
void main() {
    char* ptrMalloc;
    int* ptrCalloc;
    
    ptrMalloc = (char*)malloc(NUM_BYTES);
    ptrMalloc[1] = 5;
    if(ptrMalloc) {
        printf("Malloc Array\n");
        printCharArray(ptrMalloc, NUM_BYTES);
    }

    ptrCalloc = (int*)calloc(NUM_INTS, sizeof(int));
    ptrCalloc[1] = -5;
    if(ptrCalloc) {
        printf("Calloc Array\n");
        printIntArray(ptrCalloc, NUM_INTS);
    }

    free(ptrMalloc);
    free(ptrCalloc);
    getchar();
}
