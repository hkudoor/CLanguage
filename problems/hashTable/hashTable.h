#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include<stdlib.h>
#include<stdio.h>

// enums
typedef enum _bool {
    false,
    true
} bool;

// interface

/* hash table node */
typedef struct hashNode {
    char key[50];
    int val;
    struct hashNode* next;
} HashNode;

/* create hash table */
HashNode** createHashTable(unsigned int max);

/* print hash table */
void printTable(HashNode** tablei, unsigned int max);

/* add to hash table */
bool addToHashTable(HashNode** table, unsigned int max, char* key, int val);

/* retrieve from hash table */
bool retrieveValueFromTable(HashNode** table, unsigned int max, char* key, int* val);

#endif
