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
    bool result=false;

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

    printListSll(head);
    printf("Length = %u\n", sllLength(head));

    printf("Pushing new element at front\n");
    result = pushAtFront(&head, 42);
    printListSll(head);
    printf("Length = %u\n", sllLength(head));

    printf("Appending new element at the end\n");
    result = appendAtEnd(&head, 100);
    printListSll(head);
    printf("Length = %u\n", sllLength(head));

    getchar();
}
