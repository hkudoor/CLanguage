#include<stdlib.h>
#include<stdio.h>

// macros
#define MIN(A,B) ({\
                 __typeof__ (A) X = (A);\
                 __typeof__ (B) Y = (B);\
                 (X < Y) ? X : Y;\
                 })

#define MAX(A,B) ({\
                  __typeof__ (A) X = (A);\
                  __typeof__ (B) Y = (B);\
                  X > Y ? X : Y;\
                  })

// main
void  main() {
    int a = 5, b = 10;
    int* ptrA = &a;
    int result;
    result = MIN((*ptrA)++,b);
    printf("min = %d\n", result);

    result = MAX((*ptrA)++,b);
    printf("max = %d\n", result);
    
    printf("a = %d\n", a);
    getchar();
}
