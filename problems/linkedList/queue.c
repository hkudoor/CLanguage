#include<stdlib.h>
#include<stdio.h>
#include<linkedList.h>

// queue interface

/* is queue empty */
bool isEmptyQueue(SllNode* back) {
    return (back == NULL);
}

/* size of queue */
unsigned int queueSize(SllNode* back) {
    return sllLength(back);
}

/* read front */
bool readFront(SllNode* front, int* data) {
    if(front == NULL) {
        return false;
    }
    *data = front->data;
    return true;
}

/* enqueue */
bool enqueue(SllNode** back, SllNode** front, int data) {
    bool firstNode = false;
    bool result = false;
    
    // empty queue
    if(isEmptyQueue(*back)) {
        firstNode = true;
    }
    result = pushAtFront(back, data);
    
    // if the queue passed in was empty, 
    // set front and back are the same now
    // because the queue only has 1 element
    if(firstNode && result) {
        *front = *back;
    }
    return result;
}

/* dequeue */
bool dequeue(SllNode** back, SllNode** front, int* data) {
    SllNode* runner=NULL;
    SllNode* prevToRunner=NULL;
    bool result = false;
      
    // empty queue
    if(isEmptyQueue(*back)) {
       printf("ERR : Queue is empty, cannot dequeue\n");
       result = false;
    } else if (queueSize(*back) == 1) {
       // only 1 element in the queue
       *data = (*back)->data;
       free(*back);
       *back = *front = NULL;
       result = true;
    } else {
        // queue size > 1
        runner = (*back)->next;
        prevToRunner = *back;
        while(runner->next != NULL) {
           prevToRunner = runner;
           runner = runner->next;
        }
        *data = runner->data;
        free(runner);
        prevToRunner->next = NULL;
        *front = prevToRunner;
        result = true;
    }
    if (result == true) {
        printf("dequeued element = %d\n", *data);
    }
    return result;
}

// main
void main() {
    SllNode* front=NULL; 
    SllNode* back=NULL;
    bool result = false;
    int data = 0;

    // is queue empty
    printf("Queue is %s\n", isEmptyQueue(back) ? "EMPTY" : "NOT EMPTY");

    // enqueue 3 elements
    result = enqueue(&back, &front, 11);
    if (result == false) exit(-1);
    result = enqueue(&back, &front, 22);
    if (result == false) exit(-1);
    result = enqueue(&back, &front, 33);
    if (result == false) exit(-1);
    printListSll(back);
    printf("Queue Size = %u\n", queueSize(back));

    // dequeue once
    result = dequeue(&back, &front, &data);
    printListSll(back);
    printf("Queue Size = %u\n", queueSize(back));
     
    // read front
    result = readFront(front, &data);
    if (result == true) {
        printf("Element at the front of the queue = %d\n", data);
    }

    // dequeue 3 times
    result = dequeue(&back, &front, &data);
    result = dequeue(&back, &front, &data);
    result = dequeue(&back, &front, &data); 

    // enqueue
    result = enqueue(&back, &front, 44);
    if (result == false) exit(-1);
    printListSll(back);
    printf("Queue Size = %u\n", queueSize(back));
}
