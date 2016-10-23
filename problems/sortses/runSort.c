#include<stdlib.h>
#include<stdio.h>
#include<utils.h>
#include<sys/time.h>
#include<math.h>

// defines
#define SIZE 10000
#define MAX  2000

// helper functions

/* make an array of integers */
int* makeIntArray(unsigned int size) {
	int* array = (int*)malloc(size*sizeof(int));
	int index = 0;

	// init random num gen
	srand(time(NULL));
	for(index = 0; index < size; index++) {
		array[index] = rand()%MAX;	
	}
	return array;
}

void printArray(int* array, unsigned int size) {
	int index = 0;
	for(index=0; index<size; index++) {
		printf("%d ", array[index]);

	}
	printf("\n");

}

void slideRight(int* array, int start, int stop) {
	int index = start;
	for(index = start; index>= stop; index--) {
		array[index+1] = array[index];
	}
}

// sort functions

/* selection sort */
void sortSelection(int* array, unsigned int size, SortOrder order) {
	unsigned int tempIndex;
	int index;

	for(index=0; index<size; index++) {
		if(order == ascending) {
			tempIndex = findIndexSmallest(&array[index], size-index);
		} else if (order == descending) {
			tempIndex = findIndexBiggest(&array[index], size-index);
		}
		swap(&(array[index]), &(array[tempIndex + index]));
	}
}

/* insertion sort */
void sortInsertion(int* array, unsigned int size) {
	int runningIndex = 1, subIndex, index, key;
	bool swapNeeded = false;

	for(runningIndex = 1; runningIndex < size; runningIndex++) {
		subIndex = runningIndex - 1;
		for(index=subIndex; index>=0; index--) {
			if(array[runningIndex] < array[index]) {
				subIndex = index;
				swapNeeded = true;
			}
		}
		if(swapNeeded == false) {
			// printArray(array, size);
			continue;
		} else {
			swapNeeded = false;
			key = array[runningIndex];
			slideRight(array, runningIndex-1, subIndex);
			array[subIndex] = key;
		}
		// printArray(array, size);
	}
}

/* merge sort */
void sortMerge(int* array, unsigned int size) {
/*	if(size < 2) {
		return;
	}
	size = size/2;
	sortMerge(array, size/2
*/
}

// main
void main() {
   	int* array = NULL;
        struct timeval start, stop;
	double diffsec, diffusec;
	int index = 0;

	// form array
        array = makeIntArray(SIZE);
        if(array == NULL) {
		printf("ERR : Unable to create array\n");
		exit(-1);
	}

	// print array
	// printf("\noriginal array\n");
	// printArray(array, SIZE);
        

	// start timer
	gettimeofday(&start, NULL);

	// sort
	sortInsertion(array, SIZE);

	// stop timer
	gettimeofday(&stop, NULL);

	// print array, time
	diffsec = (stop.tv_sec - start.tv_sec);
	if(diffsec < 0) {
		diffsec += 60;
	}
	diffusec = (stop.tv_usec - start.tv_usec);
	if(diffusec < 0) {
		diffusec += 10^6;
		diffsec -= 1;
	}
	printf("Execution Time = %f milliseconds\n", (diffsec*1000 + diffusec/1000));
	// printf("\nsorted array\n");
	// printArray(array, SIZE);
	getchar();

}


