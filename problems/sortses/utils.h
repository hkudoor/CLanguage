#ifndef _UTILS_H_
#define _UTILS_H_

#include<stdlib.h>
#include<stdio.h>

// enums
typedef enum _bool {
	false,
	true
} bool;

// Interface

// sorting order
typedef enum sortOrder {
	ascending,
	descending
} SortOrder;

/* swap */
void swap(int* a, int* b);


/* min of 2 numbers */
int min(int a, int b);


/* max of 2 numbers */
int max(int a, int b);


/* find index of smallest element in array */
unsigned int findIndexSmallest(int* array, unsigned int size);


/* find index of biggest element in array */
unsigned int findIndexBiggest(int* array, unsigned int size);


#endif // (_UTILS_H_)
