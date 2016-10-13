#include<stdlib.h>
#include<stdio.h>

// defines
#define ARRAY_SIZE (10)


// globals
float* glbFloatPtr;
float  glbFloat;
float  glbFloatArray[ARRAY_SIZE];

// utility functions
void printFloatArray(float* array, size_t size) {
    int index=0;
    for(index=0; index<size; index++) {
        printf("%f ", array[index]);
    }
    printf("\n");
}

// main
void main() {
    float* localFloatPtr;
    float  localFloat, localFloatArray[ARRAY_SIZE];
    printf("global pointer = %ld, global float = %f\n", glbFloatPtr, glbFloat);
    printf("local pointer  = %ld, local float  = %f\n", localFloatPtr, localFloat);
    printf("global array : ");
    printFloatArray(glbFloatArray, ARRAY_SIZE);
    printf("local array : ");
    printFloatArray(localFloatArray, ARRAY_SIZE);
    getchar();
}
