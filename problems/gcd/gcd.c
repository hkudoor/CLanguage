#include<stdlib.h>
#include<stdio.h>


// defines


// helper functions

/* compute GCD of 2 non negative integers */
int computeGcd(int a, int b) {

    if(a < 0 || b < 0) {
    	printf("Invalid Input, please use non-negative integersn\n");
	return -1;
    }

    if(a == b) {
        return a;
    } else if(a == 0) { 
        return b;
    } else if(b == 0) {
        return a;
    } else if((a%2 == 0) && (b%2 == 0)) {
        return 2*computeGcd(a/2, b/2);
    } else if ((a%2==1) && (b%2==0)) {
        return computeGcd(a, b/2);
    } else if ((a%2==0) && (b%2==1)) {
        return computeGcd(a/2, b);
    } else if ((a%2==1) && (b%2==1)) {
        if(a>b) {
            return computeGcd((a-b)/2, b);
	} else {
            return computeGcd((b-a)/2, a);
	}
    }
}


// main
void main(int argc, char* argv[]) {
    int a; 
    int b;
    int gcd = 0;

    //  validate
    if(argc != 3) {
    	printf("ERR : not enough inputs\n");
	exit(-1);
    }

    // print inupts
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    printf("Inputs : a = %d, b = %d\n", a, b);

    // compute gcd
    gcd = computeGcd(a, b);
    if (gcd == -1) {
	exit(-1);
    }

    // print
    printf("GCD of %d & %d = %d\n", a, b, gcd);
    getchar();
}
