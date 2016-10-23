#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<binaryTree.h>

// defines
#define MAX (50)
#define NUM_NODES (25)

// main
void main() {
    BtNode* root = NULL;
	BtNode* newNode = NULL;
	unsigned int index = 0;
	unsigned int val = 0;

	root = createNode((int)MAX/2);
	if (!root) {
	    printf("ERR : Cannot create root node.\n");
		exit(-1);
	}
	srand(time(NULL));
    for(index=0; index<NUM_NODES; index++) {
		val = (int)(rand()%MAX) + 1;
		newNode = bstInsert(&root, val);
	}
	printf("Minimum = %d\n", bstFindMin(root));
	printf("Maximum = %d\n", bstFindMax(root));
	printf("\n");
	btPrint(root);
	printf("\n");
	btPrintInOrder(root);
	printf("\n");
	btPrintPostOrder(root);
	printf("\n");
	printf("Number of Nodes = %d\n", btFindNumNodes(root));
	printf("\n");
	printf("Max Depth = %d\n", btFindMaxDepth(root));
	getchar();
}

