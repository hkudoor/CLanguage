#include<stdlib.h>
#include<stdio.h>


// defines



// globals



// utility functions
char returnChar() {
    char tmp=5;
    return tmp;
}


//main
void main(int argc, char* argv[]) {
    char charFromFunc=0;
    charFromFunc = returnChar();

    printf("\n--- running %s ---\n", argv[0]);

    printf("charFromFunc = %u, %u", charFromFunc, returnChar());
    getchar();
}
