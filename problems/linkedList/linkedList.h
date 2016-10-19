#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include<stdlib.h>
#include<stdio.h>

// enums
typedef enum _bool { 
    false, 
    true
} bool;

// Interface

/* node for singly linked list*/
typedef struct sllNode {
    int data;
    struct sllNode* next;
} SllNode;

/* create node for singly linked list*/
SllNode* createSllNode(int data);

/* delete node of singly linked list*/
void deleteSllNode(SllNode* node);

/* print list */
void printListSll(SllNode* node);

/* compute length of list */
unsigned int sllLength(SllNode* node);

/* find last Element */
SllNode* findLastElement(SllNode* head); 

/* push a new element to the front of a list */
bool pushAtFront(SllNode** head, int data);

/* append element to the end of a list */
bool appendAtEnd(SllNode** headRef, int data);

/* make a copy of a list */
SllNode* copyList(SllNode* head);

#endif