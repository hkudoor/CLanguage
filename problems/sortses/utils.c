#include<stdlib.h>
#include<stdio.h>
#include<utils.h>

// Interface

/* swap */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* min of 2 numbers */
int min(int a, int b) {
	return (a < b) ? a : b;
}

/* max of 2 numbers */
int max(int a, int b) {
	return (a > b) ? a : b;
}

/* find index of smallest element in array */
unsigned int findIndexSmallest(int* array, unsigned int size) {
	if(size < 2) return 0;
	int smallestIndex = 0;
	int index;
	for (index=1; index<size; index++) {
		smallestIndex = (min(array[index], array[smallestIndex]) == array[index]) ?
				index : smallestIndex;
	}
	return smallestIndex;
}

/* find index of biggest element in array */
unsigned int findIndexBiggest(int* array, unsigned int size) {
	if(size < 2) return 0;
	int biggestIndex = 0;
	int index;
	for (index=0; index<size; index++) {
		biggestIndex = (max(array[index], array[biggestIndex]) == array[index]) ?
				index : biggestIndex;
	}
	return biggestIndex;
}
