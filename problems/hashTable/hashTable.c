#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "hashTable.h"

// Helper Functions

/* compute hash */
unsigned int hashFunction(char* key, unsigned int max) {
    unsigned int hash = -1;
    int index = 0;
    for(index=0; index<strlen((const char*)key); index++) {
        hash = (hash*max + key[index]) % max;
    }
    return hash;
}

// Interface

/* create hash table */
HashNode** createHashTable(unsigned int max) {
    HashNode** newTable = NULL;
    unsigned int index = 0;
    newTable = (HashNode**)malloc(sizeof(HashNode*)*max);
    for(index = 0; index< max; index++) {
        newTable[index] = NULL;
    }
    return newTable;
}

/* print list */
void printList(HashNode** nodeRef, int index) {
    HashNode* node = nodeRef[index];
    while(node != NULL) {
        printf(" [%d - %s : %d] -> ", index, node->key, node->val);
        node = node->next;
    }
    printf("X\n");
}

/* print hash table */
void printTable(HashNode** table, unsigned int max) {
    int index=0;
    printf("---------- TABLE -----------\n");
    for(index = 0; index<max; index++) {
        if(table[index] == NULL) {
            continue;
        } else {
            printList(table, index);
        }
    }
    printf("\n");
}

/* add to hash table */
bool addToHashTable(HashNode** table, unsigned int max, char* key, int val) {
    unsigned int hash = 0;
    HashNode* newNode;
    HashNode* runner;

    newNode = (HashNode*)malloc(sizeof(HashNode));
    if(newNode) {
       strncpy(newNode->key, key, strlen((const char*)key));
       newNode->val = val;
       newNode->next = NULL; 
    } else {
        return false;
    }

    hash = hashFunction(key, max);
    if(table[hash] == NULL) {
        table[hash] = newNode;
    } else {
        printf("Collision - appending\n");
        runner = table[hash];
        while(runner->next != NULL) {
            runner = runner->next;
        }
        runner->next = newNode;
    }
    printTable(table, max);  
    return true;
}

/* retrieve from hash table */
bool retrieveValueFromTable(HashNode** table, unsigned int max, char* key, int* val) {
    unsigned int hash = 0;
    HashNode* node = NULL;
    bool result = false;
    hash = hashFunction(key, max);
    node = table[hash];
    if(node == NULL) {
        printf("Entry NOT found \"%s\"\n", key);
        return false;
    }

    while(node != NULL) {
        if(strcmp(node->key, key) == 0) {
            *val = node->val;
            result = true;
            break;
        }
        node = node->next;
    }
    if(result == true) {
        printf("Entry found, %s = %d\n", key, *val);
    } else {
        printf("Entry NOT found \"%s\"\n", key);
    }
    return result;
}


