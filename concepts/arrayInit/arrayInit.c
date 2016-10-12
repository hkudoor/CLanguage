// when an array is instantiated
// if its Global or Static, it is initialized to 0
// if its local, a shorthand notation can be used

#include <stdio.h>

// defines
#define ARRAY_SIZE 10

// global variables
int globalArray[ARRAY_SIZE];

// utility functions
void printIntArray(int* intArray, int size) {
    int index=0;
    for(index=0; index<size; index++) {
        printf("%d ", intArray[index]);
    }
    printf("\n");
}


void localFunction() {
    int localArray[ARRAY_SIZE] = {1};
    printf("LOCAL ARRAY  : ");
    printIntArray(localArray, ARRAY_SIZE);
} 

// main
void main() {

    int index=0;
    printf("GLOBAL ARRAY : ");
    printIntArray(globalArray, ARRAY_SIZE); 
    localFunction();
    getchar();
}

