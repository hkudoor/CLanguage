#include<stdlib.h>
#include<stdio.h>
#include<hashTable.h>

// defines
#define MAX 50
#define FILE_NAME "scorecard.txt"
#define VALID_NAME "naomi"
#define INVALID_NAME "harsha"

// main
void main() {
    HashNode** table = NULL;
    FILE* filePtr = NULL;
    char name[50];
    int score;
    bool result = false;

    // create table
    table = createHashTable(MAX);
    if(table == NULL) {
        printf("ERR : unable to create table\n");
        exit(-1);
    }
    printf("INFO : Created table\n");

    // open file with names and scores
    filePtr = fopen(FILE_NAME, "r");
    if(filePtr == NULL) {
        printf("ERR : unable to open file %s\n", FILE_NAME);
        exit(-1);
    }
    printf("INFO : Opened file\n");

    // add to table
    while(fscanf(filePtr, "%s %i", name, &score) == 2) {
        addToHashTable(table, MAX, name, score);
    }
    printf("INFO : Added elements into table\n");
    printTable(table, MAX);

    // retrieve valid entry
    score = -1;
    result = retrieveValueFromTable(table, MAX, VALID_NAME, &score);
    result = retrieveValueFromTable(table, MAX, INVALID_NAME, &score);
    fclose(filePtr);
    
    getchar();
}
