#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#endif

#include<stdlib.h>
#include<stdio.h>

// defines


// globals


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
