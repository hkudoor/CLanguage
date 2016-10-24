#include<stdlib.h>
#include<stdio.h>
#include<utils.h>
#include<sys/time.h>
#include<math.h>

// defines
#define SIZE 10000
#define MAX  20000

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

void slideLeft(int* array, int start, int stop) {
	int index = start;
	for(index = start; index<=stop; index++) {
		array[index-1] = array[index];
	}
}

void merge(int* array, unsigned int startIndex, unsigned int stopIndex) {
    int firstHalfStopIndex = startIndex + (stopIndex-startIndex)/2;
    int secondHalfStartIndex = firstHalfStopIndex + 1;
    int firstHalfSize = (firstHalfStopIndex-startIndex+1);
    int secondHalfSize = (stopIndex-secondHalfStartIndex+1);
    int* firstHalf = (int*)malloc(sizeof(int)*firstHalfSize);
    int* secondHalf = (int*)malloc(sizeof(int)*secondHalfSize);
    int subArrayRunner;
    int firstHalfRunner = 0, secondHalfRunner = 0;
    int index;

    // copy elements from sub array to firstHalf and secondHalf
    for(index=startIndex; index<=stopIndex; index++) {
        if(index < secondHalfStartIndex) {
	    firstHalf[index-startIndex] = array[index];
	} else {
	    secondHalf[index-secondHalfStartIndex] = array[index];
	}
    }

    // start merge
    for(subArrayRunner=startIndex; subArrayRunner<=stopIndex; subArrayRunner++) {
        if(firstHalfRunner == firstHalfSize) {
	    array[subArrayRunner] = secondHalf[secondHalfRunner++];
	} else if (secondHalfRunner == secondHalfSize) {
	    array[subArrayRunner] = firstHalf[firstHalfRunner++];
	} else {
	    array[subArrayRunner] = (firstHalf[firstHalfRunner] < secondHalf[secondHalfRunner]) ?
	                            firstHalf[firstHalfRunner++] : secondHalf[secondHalfRunner++];
	}
    }
    // printArray(array, (stopIndex-startIndex+1));
}

/* pivot array around the selected element */
int pivotArraySlide(int* array, unsigned int size) {
    int pivotIndex = size-1;
    int pivotElem = array[pivotIndex];
    int subArrayRunner = size-2;
    int currentElement = array[subArrayRunner];


    for(subArrayRunner = size-2; subArrayRunner>=0; subArrayRunner--) {
        currentElement = array[subArrayRunner];
        if(currentElement > array[pivotIndex]) {
	    slideLeft(array, subArrayRunner+1, pivotIndex);
	    array[pivotIndex] = currentElement;
	    pivotIndex--;
	}
    }
    return pivotIndex;
}

/* pivot array around the selected element */
int pivotArray(int* array, unsigned int size) {
    int currentElement;
    int pivotIndex = size-1;
    int pivot = array[pivotIndex];
    int groupGPointer = 0, groupUPointer = 0;

    for(groupUPointer = 0; groupUPointer <= pivotIndex; groupUPointer++) {
        if(groupUPointer == pivotIndex) {
	    swap(&array[groupUPointer], &array[groupGPointer]);
	    pivotIndex = groupGPointer;
	    continue;
	}
	currentElement = array[groupUPointer];
        if(currentElement < pivot) {
	    swap(&array[groupUPointer], &array[groupGPointer]);
	    groupGPointer++;
	}
    }
    return pivotIndex;
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
			continue;
		} else {
			swapNeeded = false;
			key = array[runningIndex];
			slideRight(array, runningIndex-1, subIndex);
			array[subIndex] = key;
		}
	}
}

/* merge sort */
void sortMerge(int* array, unsigned int startIndex, unsigned int stopIndex) {
    if(startIndex >= stopIndex) {
	return;
    } else {
	sortMerge(array, startIndex, startIndex + (stopIndex-startIndex)/2);
	sortMerge(array, startIndex+((stopIndex-startIndex)/2)+1, stopIndex);
    }
    merge(array, startIndex, stopIndex);
}

/* quick sort */
void sortQuick(int* array, int startIndex, int stopIndex) {
    int pivotIndex;
    if(startIndex >= stopIndex) {
        return;
    }
    pivotIndex = pivotArray(array, (stopIndex-startIndex+1));
    sortQuick(array, 0, pivotIndex-1);
    sortQuick(&array[pivotIndex+1], 0, stopIndex-pivotIndex-1);
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
	sortQuick(array, 0, SIZE-1);

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


