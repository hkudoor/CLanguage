#include<stdlib.h>
#include<stdio.h>
#include<linkedList.h>

// defines
#define ERR_INT -9999

// stack interface functions

/* push */
bool push(SllNode** top, int data) {
	return pushAtFront(top, data);
}

/* pop */
bool pop(SllNode** top, int* data) {
	SllNode* temp=NULL;
	if (*top == NULL) {
		printf("ERR : Empty stack, cannot pop\n");
		return false;
	}
	*data = (*top)->data;
	temp = (*top)->next;
	free(*top);
	*top = temp;
	return true;
} 

/* peek */
int peek(SllNode* top) {
	return top->data;
}

/* is stack empty */
bool isEmptyStack(SllNode* top) {
	return (top == NULL);
}

/* stack size */
unsigned int stackSize(SllNode* top) {
	return sllLength(top);
}

// main
void main() {
	SllNode* top=NULL;
	bool result;
	int data=0;
	// is stack empty
	printf("Stack is %s\n", isEmptyStack(top)? "EMPTY" : "NOT EMPTY");
	
	// push 3 elements
	result = push(&top, 11);
	if (!result) exit(-1);
	result = push(&top, 22);
	if (!result) exit(-1);
	result = push(&top, 33);
	if (!result) exit(-1);
	printListSll(top);
	
	// get size 
	printf("Stack Size = %u\n", stackSize(top));
	
	// pop once
	result = pop(&top, &data);
	printf("Popped data : %d\n", data);
	if (!result) exit(-1);
	
	// get size
	printf("Stack Size = %u\n", stackSize(top));
	
	// peek
	printf("Top element data = %d\n", peek(top));
	
	// is stack empty
	printf("Stack is %s\n", isEmptyStack(top)? "EMPTY" : "NOT EMPTY");
	getchar();
}