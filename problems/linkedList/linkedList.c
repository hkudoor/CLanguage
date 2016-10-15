#include<stdlib.h>
#include<stdio.h>
#include<linkedList.h>

// Interface Definitions

/* create node for singly linked list*/
SllNode* createSllNode(int data) {
    SllNode* node;
    node = (SllNode*)malloc(sizeof(SllNode));
    if(node != NULL) {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

/* delete node of singly linked list
 * Note that this function simply frees the 
 * memory allocated for the node whose pointer
 * is passed as argument. It does NOT implement
 * a robust node deletion that takes special cases
 * into consideration, as is customary for a
 * linked list
*/
void deleteSllNode(SllNode* node) {
    if(node == NULL) {
        return;
    }

    free(node);
}

/* print list */
void printListSll(SllNode* node) {
    SllNode* runner = node;
    if(node == NULL) {
        return;
    }
    while(runner->next != NULL) {
        printf("- %d ", runner->data);
        runner = runner->next;
    }
    printf("- %d |\n", runner->data);
}

/* compute length of list */
unsigned int sllLength(SllNode* node) {
   unsigned int length = 1;
   SllNode* runner = node;
   if (node == NULL) {
       return 0;
   }
   while(runner->next != NULL) {
       length++;
       runner = runner->next;
   }
   return length;
}
