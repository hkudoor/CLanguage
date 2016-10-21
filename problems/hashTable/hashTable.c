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

/* add element at a given hash index */
void addElementAt(HashNode** table, HashNode* element, unsigned int hash) {
    HashNode* node = table[hash];
    if (node == NULL) {
        node = element;
        printf("-- Added key : %s, val : %d, at index : %u\n", element->key, element->val, hash);
        return;
    }

    while(1) {
        if (node->next != NULL) {
            node = node->next;
            continue;
        } else {
            break;
        }
    }
    node->next = element;
    printf("Added key : %s, val : %d, at index : %u\n", element->key, element->val, hash);
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

/* print hash table */
void printTable(HashNode** table, unsigned int max) {
    int index=0;
    for(index = 0; index<max; index++) {
        if(table[index] == NULL) {
            printf("%d - NULL\n", index);
        } else {
            printf("%d - %s, %d\n", index, table[index]->key, table[index]->val);
        }
    }
}

/* add to hash table */
bool addToHashTable(HashNode** table, unsigned int max, char* key, int val) {
   unsigned int hash = 0;
   HashNode* newNode = NULL;
   if(table == NULL) {
       return false;
   }
   hash = hashFunction(key, max);
   newNode = table[hash];

   if (newNode != NULL) {
       while(newNode->next != NULL) {
           newNode = newNode->next;
       }
       newNode = newNode->next;
   }

   newNode = (HashNode*)malloc(sizeof(HashNode));
   if(!newNode) return false;

   strncpy(newNode->key, key, strlen((const char*)key));
   newNode->val = val;
   newNode->next = NULL;
   return true;
}

/* retrieve from hash table */
bool retrieveValueFromTable(HashNode** table, unsigned int max, char* key, int* val) {
    unsigned int hash = 0;
    HashNode* node = NULL;
    bool result = false;
    hash = hashFunction(key, max);
    printf("INFO : RETRIEVAL - computed hash \"%u\"\n", hash);
    node = table[hash];
    if(node == NULL) {
        return false;
    }

    printf("INFO : checkpoint1\n");
    if(node->next == NULL) {
        printf("INFO : RETRIEVAL - single element at index %u\n", hash);
        *val = node->val;
        result = true;
    } else {
        printf("INFO : checkpoint2\n");
        while(node != NULL) {
            if(strcmp(node->key, key) == 0) {
                *val = node->val;
                break;
            }
            node = node->next;
        }
    }
    if(result) {
        printf("Entry found, %s = %d\n", key, *val);
    } else {
        printf("Entry NOT found \"%s\"\n", key);
    }
    return result;
}


