#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<stdint.h>

// gobals
int globalInt = 0;

// helper functions

/* thread 1 */
void* threadOne() {
    u_int8_t index = 0;
    for(index = 0; index < 100; index++) {
        globalInt++;
    }
    printf("*** Thread1 ***\n");
    pthread_exit(NULL);
}

/* thread 2 */
void* threadTwo() {
    u_int8_t index = 0;
    for(index = 0; index < 200; index++) {
        globalInt++;
    }
    printf("*** Thread2 ***\n");
    pthread_exit(NULL);
}

// main
void main() {
    pthread_t thread1, thread2;
    long t;
    int rc;
    
    // create thread 1
    rc = pthread_create(&thread1, NULL, threadOne, (void*)t); 

    // create thread 2
    rc = pthread_create(&thread2, NULL, threadTwo, (void*)t);

    // wait for threads to finish
    (void)pthread_join(thread1, NULL);
    (void)pthread_join(thread2, NULL);

    // print globalInt
    printf("global int = %d\n", globalInt);
    getchar();
}
