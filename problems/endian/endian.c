#include<stdlib.h>
#include<stdio.h>


// main
int main(int argc, char* argv[]) {

    int num = 1;
    char* c = (char*)&num;
    printf("the system is %s\n", (c[0] == 1 ? "LITTLE ENDIAN" : "BIG ENDIAN"));
    getchar();
}
