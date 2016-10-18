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

/* print binary tree in-order */
void btPrintInOrder(BtNode* root) {
	if(root->left == NULL && root->right == NULL) {
		printf("%d   ", root->data);
	} else if (root->left == NULL && root->right != NULL) {
		printf("%d  ", root->data);
		btPrintInOrder(root->right);
	} else if (root->left != NULL && root->right == NULL) {
		btPrintInOrder(root->left);
		printf("%d  ", root->data);
	} else {
		btPrintInOrder(root->left);
		printf("%d  ", root->data);
		btPrintInOrder(root->right);
	}
}

/* find minimum in a BST */
int bstFindMin(BtNode* root) {
	if(root->left == NULL) {
		return root->data;
	} else {
		return bstFindMin(root->left);
	}
}

/* find maximum in a BST */
int bstFindMax(BtNode* root) {
	if(root->right == NULL) {
		return root->data;
	} else {
		return bstFindMax(root->right);
	}
}

/* find number of nodes in a binary tree */
int btFindNumNodes(BtNode* root) {
	if(root == NULL) {
		return 0;
	} else {
		return btFindNumNodes(root->left) + btFindNumNodes(root->right) + 1;
	}
}

/* find max depth of a binary tree */
int btFindMaxDepth(BtNode* root) {
    static int currentDepth;
	return 0;
		
}