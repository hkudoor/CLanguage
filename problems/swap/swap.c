#include<stdlib.h>
#include<stdio.h>

// defines



// globals



// utility functions
void swap(int* A, int* B) {
    int tmp=*B;
    *B = *A;
    *A = tmp;
}


// main
void main() {
    int a=10, b=15;
    printf("Before SWAP : a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("After SWAP : a=%d, b=%d\n", a, b);
    getchar();

}
