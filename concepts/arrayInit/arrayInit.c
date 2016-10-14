// when an array is instantiated
// if its Global or Static, it is initialized to 0
// if its local, a shorthand notation can be used

#include<stdlib.h>
#include<stdio.h>
#include<utils.h>

// defines
#define ARRAY_SIZE 10

// global variables
int globalArray[ARRAY_SIZE];

// helper functions
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

