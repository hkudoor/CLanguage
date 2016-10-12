#include<stdlib.h>
#include<stdio.h>

// defines
#define NUM_BYTES 100
#define NUM_INTS  25

// utility functions


// main
void main() {
    char* ptrMalloc;
    int* ptrCalloc;
    
    ptrMalloc = (char*)malloc(NUM_BYTES);
    if(ptrMalloc)
        printf("Malloc Size = %d\n", sizeof(ptrMalloc));

    ptrCalloc = (int*)calloc(NUM_INTS, sizeof(int));
    if(ptrCalloc)
        printf("Calloc Size = %d\n",sizeof(ptrCalloc));

    getchar();
}
