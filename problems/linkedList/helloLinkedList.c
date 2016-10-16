#include<stdlib.h>
#include<stdio.h>
#include<linkedList.h>

// defines
#define NUM_ELEMENTS 2

// globals
SllNode* head;
SllNode* newList;

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

    // print List
    printListSll(head);
    printf("Length = %u\n", sllLength(head));

    // add element at the front
    printf("\nPushing new element at front\n");
    result = pushAtFront(&head, 42);
    if(result == true) {
        printListSll(head);
        printf("Length = %u\n", sllLength(head));
    } else {
        return;
    }

    // add element at the end
    printf("\nAppending new element at the end\n");
    result = appendAtEnd(&head, 100);
    if(result == true) {
        printListSll(head);
        printf("Length = %u\n", sllLength(head));
    } else {
        return;
    }


    // copy List
    printf("\nCopying list\n");
    newList = copyList(head);
    if(newList != NULL) {
        printListSll(newList);
        printf("Length = %u\n", sllLength(newList));
    } else {
        return;
    }

    // cleanup
    getchar();
}
