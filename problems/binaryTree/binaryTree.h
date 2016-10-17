#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
#endif

#include<stdlib.h>
#include<stdio.h>

// enums
typedef enum _bool {
    false,
    true
} bool;

// Interface

/* structure of node */
typedef struct btNode {
    int data;
    struct btNode* left;
    struct btNode* right;
} BtNode;

/* create node */
BtNode* createNode(int data);

/* search for a value in a BST */
bool bstLookup(BtNode* root, int val);

/* insert node into a BST */
BtNode* bstInsert(BtNode** rootRef, int val);

/* print binary tree */
void btPrint(BtNode* root);

