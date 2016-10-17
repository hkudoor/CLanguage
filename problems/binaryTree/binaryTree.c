#include<stdlib.h>
#include<stdio.h>
#include<binaryTree.h>

// Interface

/* create node */
BtNode* createNode(int data) {
    BtNode* newNode = NULL;
    newNode = (BtNode*)malloc(sizeof(BtNode));
    if(newNode == NULL) {
        printf("ERR : Out of memory");
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    printf("INFO : Created new node with data : %d\n", newNode->data);
    return newNode;
}

/* search for a value in a BST */
bool bstLookup(BtNode* root, int val) {
    bool result=false;
    if(root == NULL) {
        result = false;
    } else if (root->data == val) {
        result = true;
    } else {
        result = (val <= root->data) ? bstLookup(root->left, val) :
                                       bstLookup(root->right, val) ;
    }
    return result;
}

/* insert node into a BST */
BtNode* bstInsert(BtNode** rootRef, int val) {
    BtNode* newNode = NULL;
    if(*rootRef == NULL) {
        newNode = createNode(val); 
        if(newNode != NULL) {
            *rootRef = newNode;
        } 
    } else {
        newNode = (val <= (*rootRef)->data) ? bstInsert(&(*rootRef)->left, val) :
                                              bstInsert(&(*rootRef)->right, val);
    }
    return newNode;
}

/* print binary tree */
void btPrint(BtNode* root) {
    if(root == NULL) {
        printf("X   ");
    } else {
        printf("%d  ", root->data);
        btPrint(root->left);
        printf("\n");
        btPrint(root->right);
    }
}
