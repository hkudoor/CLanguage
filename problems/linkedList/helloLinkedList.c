#include<stdlib.h>
#include<stdio.h>
#include<linkedList.h>

// defines
#define NUM_ELEMENTS 2

// globals
SllNode* head;

// main
void main() {

    SllNode* runner = NULL;
    unsigned char index = 0;

    // start list
    head = createSllNode(1);
    if(head == NULL) {
        printf("ERR : Out of memory\n");
        exit(-1);
    }
    runner = head;

    // link 2 other elements
    for(index=0; index<NUM_ELEMENTS; index++) {
        runner->next = createSllNode(index+2);
        if(runner->next == NULL) {
            printf("ERR : Out of memory\n");
            exit(-1);
        }
        runner = runner->next;
    }

    // print list
    printListSll(head);
    printf("Length = %u\n", sllLength(head));
    getchar();
}
