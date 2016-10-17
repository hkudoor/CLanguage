#include<stdlib.h>
#include<stdio.h>
#include<binaryTree.h>

// defines
#define DATA1 (1)
#define DATA2 (2)
#define DATA3 (3)
#define DATA4 (4)
#define DATA5 (5)
#define DATA6 (6)
#define DATA7 (7)
#define DATA13 (13)

// main
void main() {
    BtNode* root = NULL;
    BtNode* node;
    root = bstInsert(&root, DATA4);
    if(root) {
        node = bstInsert(&root, DATA2);
        node = bstInsert(&root, DATA1);
        node = bstInsert(&root, DATA3);
        node = bstInsert(&root, DATA6);
        node = bstInsert(&root, DATA5);
        node = bstInsert(&root, DATA7);
        node = bstInsert(&root, DATA13);
    }
    btPrint(root);
    getchar();
}
