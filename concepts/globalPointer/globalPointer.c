#include<stdlib.h>
#include<stdio.h>
#include<utils.h>

// defines
#define ARRAY_SIZE (10)

// globals
float* glbFloatPtr;
float  glbFloat;
float  glbFloatArray[ARRAY_SIZE];

// main
void main() {
    float* localFloatPtr;
    float  localFloat, localFloatArray[ARRAY_SIZE];
    printf("global pointer = %lu, global float = %f\n", (long unsigned int)glbFloatPtr, glbFloat);
    printf("local pointer  = %lu, local float  = %f\n", (long unsigned int)localFloatPtr, localFloat);
    printf("global array : ");
    printFloatArray(glbFloatArray, ARRAY_SIZE);
    printf("local array : ");
    printFloatArray(localFloatArray, ARRAY_SIZE);
    getchar();
}
